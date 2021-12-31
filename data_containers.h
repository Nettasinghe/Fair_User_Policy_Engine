

//////////////////////////////////////////////////////////////////////
//
// data_containers.h
// FUP Engine 
// definitions for classes for FUP Engine
// developer - Chandika Nettasinghe
// code start - 2008-January
//
//////////////////////////////////////////////////////////////////////


#pragma warning(disable:4786)

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
#include <fstream>

using namespace std;

#define MIN_YEAR 1949
#define MAX_YEAR 2051
#define BULK_INSERT_SIZE 5000


void	db_connect_cust_care(char *in_login); 
void	db_connect_rating(char *in_login); 
void	db_disconnect_cust_care();
void	db_disconnect_rating();

// -------------FUP_Engine-------------------------

/*

	POLICY_CODE,       //VARCHAR2(10)           NOT NULL,
  THRESHOLD_START,	//NUMBER(10)	   NOT NULL, -- SIZE IN KB
THRESHOLD_END,	//NUMBER(10)	   NOT NULL, -- SIZE IN KB
  PDP_Model_ID		//varchar2(15)	  	   NOT NULL,
  
from PM_FUP_POLICY_THRESHOLDS;

Put to PM_FUP_POLICY_THRESHOLDS map - key = POLICY_CODE, THRESHOLD_START
*/


class policy_threshold
{
public:
	string	policy_code;
	double 	threshold_start;
	double 	threshold_end;
	string	pdp_model_id;
	
	bool init()
	{
		policy_code			= "";
		threshold_start		= 0;
		threshold_end		= 0;
		pdp_model_id		= "";
		return true;
	};
};

class policy_threshold_key
{
public:
	string	policy_code;
	double 	threshold_start;
		
	bool init()
	{
		policy_code			= "";
		threshold_start		= 0;
		return true;
	};
	bool operator < (const policy_threshold_key  &s) const;
};

typedef map<policy_threshold_key , policy_threshold, less<policy_threshold_key> > POLICY_THRESHOLD_DEF;		

/*
IMAGE_ID,	//  		NUMBER(10)        NOT NULL,				 
  GPRS_CONNECTION_ID,	//	NUMBER(10)        NOT NULL,
  GPRS_STATUS;		//	VARCHAR2(2)		NOT NULL
  CONTRACT_ID,	//        	NUMBER(10)        NOT NULL,
  POLICY_CODE,    //		VARCHAR2(10)	  NOT NULL,
  Active_PDP_Model_ID,//		varchar2(15)	  NOT NULL,
Date_PDP_Changed,	//		date,	
USED_GPRS			// number(15,2)

ROWID
From FUP_CX_ATTACHMENT_V
Where EXTENDED_FUP = 'N'  -- no need to consider because the CX has paid in advance for the extension
	AND GPRS_STATUS = 'C'

Put to FUP_CX_ATTACHMENT_V map. = Key = 	IMAGE_ID, Data 'Changed'-default 'NO'
Put to FUP_CX_ATTACHMENT_V_CON_ID map. = Key = CONTRACT_ID	
*/

class fup_cx_attachment
{
public:
	double	image_id;
	double 	gprs_connection_id;
	string	gprs_status;
	double	contract_id;
	string	policy_code;
	string	active_pdp_model_id;
	string	date_pdp_changed;
	double	used_gprs;
	string	row_id;
	bool	changed;
		
	bool init()
	{
		image_id			= 0;
	 	gprs_connection_id	= 0;
		gprs_status			="";
		contract_id			= 0;
		policy_code			="";
		active_pdp_model_id	="";
		date_pdp_changed	="";
		used_gprs			= 0;
		row_id				="";
		changed				= false;
		return true;
	};
};

typedef map<double , fup_cx_attachment, less<double> > CX_ATTACH_DEF;	// key = image_id

typedef map<double , fup_cx_attachment, less<double> > CX_ATTACH_CON_ID_DEF;	// key = contract_id	

typedef map<double , string, less<double> > CX_PDP_MODEL_ID_DEF;	// key = contract_id	

/*
NODE_ID,               // NUMBER (10), 
  VALUE,                 // NUMBER (14,6), 
  ITEM_CODE              //VARCHAR2 (10), 
From BILL_DETAIL_ITEMS_I;

Put to BILL_DETAIL_ITEMS_I map if item_code == 'VOL_GPRS' - Key = NODE_ID
*/

class bill_detail_item
{
public:
	double	node_id;
	double 	value;
	string	item_code;
			
	bool init()
	{
		node_id		= 0;
	 	value		= 0;
		item_code	="";
		return true;
	};
};

typedef map<double , bill_detail_item, less<double> > BILL_DETAIL_ITEM_DEF;	// key = node_id

/*
IMAGE_ID, 	// N10	- NN
CONNECTION_ID,	// N10	-NN 
PDP_MODEL_ID, 	//VC15	-NN
STATUS		// VC2 -NN
From gprs_pdp_customers	

Put to gprs_pdp_customers map - Key IMAGE_ID, CONNECTION_ID, PDP_MODEL_ID
*/


class gprs_pdp_customer
{
public:
	double	image_id;
	double 	connection_id;
	string	pdp_model_id;
	string	status;
			
	bool init()
	{
		image_id		= 0;
	 	connection_id	= 0;
		pdp_model_id	="";
		status			="";
		return true;
	};
};

class gprs_pdp_customer_key
{
public:
	double	image_id;
	double 	connection_id;
	string	pdp_model_id;
				
	bool init()
	{
		image_id		= 0;
	 	connection_id	= 0;
		pdp_model_id	="";
		return true;
	};
	bool operator < (const gprs_pdp_customer_key  &s) const;
};


typedef map<gprs_pdp_customer_key , gprs_pdp_customer, less<gprs_pdp_customer_key> > GPRS_PDP_CX_DEF;	

// -------------FUF_ENGINE - end---------------------



// -------------reng_date_time---------------------

class reng_time;

class reng_time
{
public:
	int hour;
	int min;
	int second;
	bool set_time(int h, int m, int s=0);
	bool set_time(char *t);
	bool set_h_m(const char *t);
	bool set_from_db(char *t, int secs);

	bool operator < (const reng_time  &s) const;
	reng_time operator+ (int s) const;
	void Print();
	void init();
};


ostream& operator<<(ostream& out, reng_time x);

class reng_date
{
public:
	int year;
	int month;
	int day;
	bool operator < (const reng_date  &s) const;
	bool operator == (const reng_date  &s) const;
	bool set_date(int y, int m, int d);
	bool set_date(char *d);
	void init();
};

ostream& operator<<(ostream& out, reng_date x);


class reng_date_time
{
public:
	reng_date date;
	reng_time time;
	bool set_date_time(char *d);
	bool operator < (const reng_date_time  &s) const;
};

ostream& operator<<(ostream& out, reng_date_time x);

// -------------reng_date_time-end---------------------





class churn
{
public:
	
	//string	sys_date;

	//-------FUP Start--------------------

	POLICY_THRESHOLD_DEF	policy_threshold_map;
	CX_ATTACH_DEF			cx_attach_map;
	CX_ATTACH_CON_ID_DEF	cx_attach_con_id_map;
	CX_ATTACH_CON_ID_DEF	cx_attach_con_id_changed_map;
	//CX_PDP_MODEL_ID_DEF		cx_attach_con_id_changed_map;
	BILL_DETAIL_ITEM_DEF	bill_detail_item_map;
	GPRS_PDP_CX_DEF			gprs_pdp_cx_map;

	void churn::db_read_pm_fup_policy_thresholds();
	void churn::db_read_fup_cx_attachment_v();
	void churn::db_read_bill_detail_items_i();
	void churn::db_read_gprs_pdp_customers();
	void churn::db_update_fup_cx_attachment();
	void churn::process_fup();

	void churn::print_policy_threshold_map();
	void churn::print_cx_attach_map();
	void churn::print_cx_attach_con_id_map();
	void churn::print_bill_detail_item_map();
	void churn::print_gprs_pdp_cx_map();

	bool churn::activate_deactivate_pdp(string pdp_model_found, double image_id, double connection_id, string action);
	bool churn::install_pdp(string pdp_model_found, double image_id, double connection_id, string sys_date);
	//-------FUP End-----------------------

	
	char*		sys_date;		// hlr_ccbs

public:
	FILE *log_to_file;
	
	churn(const char* LogFileName)
	{
		
		sys_date		= new char[128];		// hlr_ccbs

		//check_date		= new char[128];		// hlr_ccbs

		/*
		if ((log_to_file = fopen(LogFileName, "w"))==NULL)
		{
			cout << "Can't create log file " << LogFileName << endl;
			exit (0);
		}
		*/
		
	}

	~churn()
	{
		//cout << "Distructor called" << endl;
		
		/*
		if( fclose( log_to_file ) )
			cout <<  "The log file was not closed\n" << endl;
			*/
			
	}

	
	void	get_db_sysdate();

	//void	db_get_sysdate();		// for hlr_ccbs
	
	//float	db_first_minus_second(char* first_date, char* second_date);	// for hlr_ccbs

	
};

