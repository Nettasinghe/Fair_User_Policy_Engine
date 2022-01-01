

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Fair User Policy Engine (FUP Engine) -
// Fair usage policies limit the usage of one user over another at peak times so that the performance 
// is not affected for the rest of the group. Fair User Policy Engine implements this logic by 
// fetching the data usages of data service subscribers from the database at real time and facilitate 
// downgrading of the bandwidth of the subscribers who has exceeded the configured threshold levels.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//
// main.cpp
// FUP Engine 
// main method contains here
// developer - Chandika Nettasinghe
// code start - 2008-January
//
//////////////////////////////////////////////////////////////////////

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 27-feb-2008 ver 1.0.0
//	1) Initial Production Version
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




#include <fstream>
#include <time.h>

#include "data_containers.h"

	churn		*gsm_churn;
	char		*LogFileName;
	
	ofstream f_log("./logs/FUP_Engine.log", ios::out | ios::app);
	FILE* fp = NULL;
	

int main(int argc,char *argv[])
{
	char *ver = "1.0.0_PRODUCTION";

	// Log file
	char zTime[30];
	/*------- get time -------*/
	time_t t;
	time(&t);
	/*------- get time -------*/
	strftime(zTime, 30, "%Y%B%d%H%M%S", localtime(&t));
	LogFileName = new char[100];
	//sprintf(LogFileName, "./hlr_ccbs_mismatch_%s.csv",zTime);
	// Log file -end

	//+++++++++++++++++++++++++++


	//////////////////////////////////////////////////
	char z_File[500];
	sprintf(z_File,"./logs/FUP_Engine.log.%s",zTime);
	fp = fopen(z_File,"w");
	if(fp == NULL)
	{
		printf("Error openning file %s",z_File);
		exit(0);
	}
	fprintf(fp,"FUP Engine %s\nBuild Time %s at %s\nDialog Telekom\nColombo, Sri Lanka\n\n",ver,__DATE__,__TIME__);
	printf("FUP Engine %s\nBuild Time %s at %s\nDialog Telekom\nColombo, Sri Lanka\n\n",ver,__DATE__,__TIME__);
	//////////////////////////////////////////////////

	gsm_churn				= new churn( (const char*)LogFileName);

	

	FILE *login;
	
	char rating_login[128];

	// get config data
	if( (login  = fopen( "./fup.config", "r" )) == NULL )
	{
		printf( "The file 'fup.config' was not opened\n" );
		exit(0);
	}

	fscanf( login, "%s", rating_login );


	if( fclose( login ) )
		printf( "The file 'fup.config' was not closed\n" );

	sprintf(LogFileName, "./fup_engine_%s%s.log",zTime, gsm_churn->sys_date );

	db_connect_rating(rating_login);

	gsm_churn->get_db_sysdate();

	fprintf(fp,"sys_date = %s|\n",gsm_churn->sys_date);
	printf("sys_date = %s|\n",gsm_churn->sys_date);

	
	cout << "Reading pm_fup_policy_thresholds ........." << endl;
	gsm_churn->db_read_pm_fup_policy_thresholds();

	cout << "Logging policy_threshold_map ............." << endl;
	gsm_churn->print_policy_threshold_map();

	cout << "Reading fup_cx_attachment_v ........." << endl;
	gsm_churn->db_read_fup_cx_attachment_v();

	cout << "Logging cx_attach_map ............." << endl;
	gsm_churn->print_cx_attach_map();
	cout << "Logging cx_attach_con_id_map ............." << endl;
	gsm_churn->print_cx_attach_con_id_map();
	
	cout << "Reading bill_detail_items_i_v ........." << endl;
	gsm_churn->db_read_bill_detail_items_i();
	
	cout << "Logging bill_detail_item_map ............." << endl;
	fprintf(fp,"+++++++++++++++++++++++++++++++++++++++\n");
	fprintf(fp,"Printing bill_detail_item_map\n\n");
	gsm_churn->print_bill_detail_item_map();
	
	cout << "Reading GPRS_PDP_CUSTOMERS_V ........." << endl;
	gsm_churn->db_read_gprs_pdp_customers();

	cout << "Logging gprs_pdp_cx_map ............." << endl;
	gsm_churn->print_gprs_pdp_cx_map();
	
	cout << "Processing ........." << endl;
	gsm_churn->process_fup();

	cout << "Updating fup_cx_attachment........." << endl;

	gsm_churn->db_update_fup_cx_attachment();

	delete gsm_churn;

	cout << "Disconnecting from Database" << endl;

	db_disconnect_rating();

	cout << "Disconnected from Database" << endl;

	

	////////////////////////////////////////////////
	fprintf(fp, "\nFUP Engine process completed\n");

	if(fclose(fp) != 0)
		printf("Error closing file %s",z_File);
	////////////////////////////////////////////////

	printf("\nFUP Engine process completed\n");

	return 0;
}


