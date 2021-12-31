

//////////////////////////////////////////////////////////////////////
//
// fup.cpp
// FUP Engine 
// class implementation for FUP Engine
// developer - Chandika Nettasinghe
// code start - 2008-January
//
//////////////////////////////////////////////////////////////////////



#include "data_containers.h"
#include <stdio.h>

#include <iostream>

extern	churn	*	gsm_churn;
extern  FILE* fp;

bool policy_threshold_key::operator < (const policy_threshold_key  &s) const
{
	if(policy_code < s.policy_code)
		return true;
	if ((policy_code == s.policy_code) && (threshold_start < s.threshold_start))
		return true;
	
	return false;
}

bool gprs_pdp_customer_key::operator < (const gprs_pdp_customer_key  &s) const
{
	if(image_id < s.image_id)
		return true;
	if ((image_id == s.image_id) && (connection_id < s.connection_id))
		return true;
	if ((image_id == s.image_id) && (connection_id == s.connection_id) && (pdp_model_id < s.pdp_model_id))
		return true;
	
	
	return false;
}

void churn::process_fup()
{
	//POLICY_THRESHOLD_DEF	policy_threshold_map;
	//CX_ATTACH_DEF			cx_attach_map;
	//CX_ATTACH_CON_ID_DEF	cx_attach_con_id_map;
	//BILL_DETAIL_ITEM_DEF	bill_detail_item_map;
	//GPRS_PDP_CX_DEF			gprs_pdp_cx_map;

	CX_ATTACH_CON_ID_DEF::iterator	i_con_id;
	BILL_DETAIL_ITEM_DEF::iterator	i_bill_item;
	POLICY_THRESHOLD_DEF::iterator	i_policy_threshold;
	GPRS_PDP_CX_DEF::iterator		i_pdp_cx;

	gprs_pdp_customer_key	cx_key;
	fup_cx_attachment		cx_attach;

	double	vol_gprs_value	= 0;

	for(i_con_id =cx_attach_con_id_map.begin(); i_con_id!=cx_attach_con_id_map.end(); i_con_id++)
	{
		i_bill_item = bill_detail_item_map.find((*i_con_id).first);

		if (i_bill_item == bill_detail_item_map.end() )
		{
			double dContractID = (double)(*i_con_id).first;
			//std::cout << "Bill_detail_item is not found for contract_id : " << dContractID << " in FUP_CX_ATTACHMENT_V" << std::endl;
			fprintf(fp,"Bill_detail_item is not found for contract_id : %.2f in FUP_CX_ATTACHMENT_V\n",dContractID);
			// What to do?
		}
		else
		{
			fprintf(fp,"Bill_detail_item is found for contract_id : %.2f in FUP_CX_ATTACHMENT_V\n",(*i_con_id).first);
			vol_gprs_value = (*i_bill_item).second.value;
			fprintf(fp,"vol_gprs_value = %.2f\n",vol_gprs_value);

			for(i_policy_threshold = policy_threshold_map.begin(); i_policy_threshold != policy_threshold_map.end(); i_policy_threshold++)
			{
				fprintf(fp,"Traverse through policy_threshold_map\n");
				fprintf(fp,"used_gprs = %.2f\n",((*i_con_id).second.used_gprs));
				fprintf(fp,"vol_gprs - used_gprs = %.2f\n",((*i_bill_item).second.value - (*i_con_id).second.used_gprs ));
				fprintf(fp,"PM_FUP_POLICY_THRESHOLDS - policy_code = %s|\n",(*i_policy_threshold).second.policy_code.c_str());
				fprintf(fp,"FUP_CX_ATTACHMENT_V - policy_code = %s|\n",(*i_con_id).second.policy_code.c_str());
				fprintf(fp,"(*i_con_id).second.active_pdp_model_id = %s|\n",(*i_con_id).second.active_pdp_model_id.c_str());
				fprintf(fp,"(*i_policy_threshold).second.pdp_model_id = %s|\n",(*i_policy_threshold).second.pdp_model_id.c_str());

				if (( strcmp((const char*)(*i_policy_threshold).second.policy_code.c_str(), (const char*)(*i_con_id).second.policy_code.c_str()) == 0 )//) 
					&&
					( ( (*i_bill_item).second.value - (*i_con_id).second.used_gprs ) > (*i_policy_threshold).second.threshold_start) 
					&&
					( ( (*i_bill_item).second.value - (*i_con_id).second.used_gprs ) <= (*i_policy_threshold).second.threshold_end ) )
				{
					if ( strcmp((const char*)(*i_policy_threshold).second.pdp_model_id.c_str(), (const char*)(*i_con_id).second.active_pdp_model_id.c_str())==0)
					{
						fprintf(fp,"(*i_policy_threshold).second.pdp_model_id =  (*i_policy_threshold).second.pdp_model_id \n");
						fprintf(fp,"Hence do nothing\n");
						fprintf(fp,"-------------------------------------\n");

						// Do nothing
					}
					else
					{
						cx_key.init();

						cx_key.image_id			= (*i_con_id).second.image_id;
						cx_key.connection_id	= (*i_con_id).second.gprs_connection_id;
						cx_key.pdp_model_id		= (*i_policy_threshold).second.pdp_model_id;

						fprintf(fp,"(*i_con_id).second.image_id = %.2f\n",(*i_con_id).second.image_id);
						fprintf(fp,"(*i_con_id).second.gprs_connection_id = %.2f\n",(*i_con_id).second.gprs_connection_id);
						fprintf(fp,"(*i_policy_threshold).second.pdp_model_id = %s\n",(*i_policy_threshold).second.pdp_model_id.c_str());
						fprintf(fp,"==============================================================\n");

						i_pdp_cx = gprs_pdp_cx_map.find(cx_key);

						if (i_pdp_cx != gprs_pdp_cx_map.end() )
						{
							// Match found

							fprintf(fp,"Match found in gprs_pdp_cx_map\n");
							fprintf(fp,"(*i_pdp_cx).first.image_id = %.2f\n",(*i_pdp_cx).first.image_id);
							fprintf(fp,"(*i_pdp_cx).first.connection_id = %.2f",(*i_pdp_cx).first.connection_id); 
							fprintf(fp,"(*i_pdp_cx).first.pdp_model_id = %s\n\n",(*i_pdp_cx).first.pdp_model_id.c_str());
							
							fprintf(fp,"(*i_pdp_cx).second.status = %s\n",(*i_pdp_cx).second.status.c_str());

							(*i_con_id).second.changed = true;
							cx_attach.init();
							cx_attach.changed	= true;
							cx_attach.row_id	= (*i_con_id).second.row_id;
							cx_attach.active_pdp_model_id = cx_key.pdp_model_id;

							cx_attach_con_id_changed_map.insert(CX_ATTACH_CON_ID_DEF::value_type((*i_con_id).first, cx_attach));
							//cx_attach_con_id_changed_map.insert(CX_PDP_MODEL_ID_DEF::value_type((*i_con_id).first, cx_key.pdp_model_id));

							
							if ( strcmp((const char*)(*i_pdp_cx).second.status.c_str(), "T")==0)
							{
								// Disconnect PDP & Connect PDP
								fprintf(fp,"Status T Hence Disconnect PDP & Connect PDP\n");
								activate_deactivate_pdp((*i_con_id).second.active_pdp_model_id, cx_key.image_id, cx_key.connection_id, "T");
								activate_deactivate_pdp(cx_key.pdp_model_id, cx_key.image_id, cx_key.connection_id, "C");
								
							}

							if ( strcmp((const char*)(*i_pdp_cx).second.status.c_str(), "C")==0)
							{
								// Log Bad Data
								fprintf(fp,"Status C Hence Log Bad Data\n");
							}
						}
						else
						{
							// Match not found
							fprintf(fp,"Match not found\n");

							cx_attach.init();
							cx_attach.changed	= true;
							cx_attach.row_id	= (*i_con_id).second.row_id;
							cx_attach.active_pdp_model_id = cx_key.pdp_model_id;

							cx_attach_con_id_changed_map.insert(CX_ATTACH_CON_ID_DEF::value_type((*i_con_id).first, cx_attach));
							
							
							// Disconnect PDP & Install PDP
							//cout << "Match not found" << endl;
							fprintf(fp,"Hence Disconnect PDP & Install PDP\n");

							activate_deactivate_pdp((*i_con_id).second.active_pdp_model_id, cx_key.image_id, cx_key.connection_id, "T");

							install_pdp(cx_key.pdp_model_id,
								cx_key.image_id,
								cx_key.connection_id,
								sys_date);
							
						}
					}
				}
			}
			//(*i_con_id).second.policy_code
			//(*i_con_id).second.used_gprs
			//(*i_bill_item).second.value
		}
	}

	/*
	for(i_con_id =cx_attach_con_id_map.begin(); i_con_id!=cx_attach_con_id_map.end(); i_con_id++)
	{
		if ( (*i_con_id).second.changed == true )
		{
		}
	}*/
}


void churn::print_policy_threshold_map()
{
	POLICY_THRESHOLD_DEF::iterator	i_policy_threshold;

	for(i_policy_threshold = policy_threshold_map.begin(); i_policy_threshold != policy_threshold_map.end(); i_policy_threshold++)
	{
		//c//out << (*i_policy_threshold).first.c_str() << endl;
		fprintf(fp,"-------------------------------------------------------------------\n");
		fprintf(fp,"k_policy_code= %s\n\n",(*i_policy_threshold).first.policy_code.c_str());
		//cout << "k_threshold_start= " << (*i_policy_threshold).first.threshold_start << endl;
		fprintf(fp,"policy_code= %s\n\n",(*i_policy_threshold).second.policy_code.c_str());
		fprintf(fp,"threshold_start= %.2f\n",(*i_policy_threshold).second.threshold_start);
		fprintf(fp,"threshold_end= %.2f\n",(*i_policy_threshold).second.threshold_end);
		fprintf(fp,"pdp_model_id= %s\n",(*i_policy_threshold).second.pdp_model_id.c_str());
	}
}

void churn::print_cx_attach_map()
{
	CX_ATTACH_DEF::iterator	i;

	for(i = cx_attach_map.begin(); i != cx_attach_map.end(); i++)
	{
		fprintf(fp,"-------------------------------------------------------------------\n");
		fprintf(fp,"k_image_id= %.2f\n",(*i).first);
		fprintf(fp,"image_id= %.2f\n",(*i).second.image_id);
		fprintf(fp,"gprs_connection_id= %.2f\n",(*i).second.gprs_connection_id);
		fprintf(fp,"gprs_status= %s\n",(*i).second.gprs_status.c_str());
		fprintf(fp,"contract_id= %.2f\n",(*i).second.contract_id);
		fprintf(fp,"policy_code= %s\n",(*i).second.policy_code.c_str());
		fprintf(fp,"active_pdp_model_id= %s\n",(*i).second.active_pdp_model_id.c_str());
		fprintf(fp,"date_pdp_changed= %s\n",(*i).second.date_pdp_changed.c_str());
		fprintf(fp,"used_gprs= %.2f\n",(*i).second.used_gprs);
		fprintf(fp,"row_id= %s\n",(*i).second.row_id.c_str());
		fprintf(fp,"changed= %d\n",(*i).second.changed);
	}
}

void churn::print_cx_attach_con_id_map()
{
	CX_ATTACH_CON_ID_DEF::iterator	i;

	for(i = cx_attach_con_id_map.begin(); i != cx_attach_con_id_map.end(); i++)
	{
		fprintf(fp,"-------------------------------------------------------------------\n");
		fprintf(fp,"k_contract_id= %.2f\n\n",(*i).first);
		fprintf(fp,"image_id= %.2f\n",(*i).second.image_id);
		fprintf(fp,"gprs_connection_id= %.2f\n",(*i).second.gprs_connection_id);
		fprintf(fp,"gprs_status= %s\n",(*i).second.gprs_status.c_str());
		fprintf(fp,"contract_id= %.2f\n",(*i).second.contract_id);
		fprintf(fp,"policy_code= %s\n",(*i).second.policy_code.c_str());
		fprintf(fp,"active_pdp_model_id= %s\n",(*i).second.active_pdp_model_id.c_str());
		fprintf(fp,"date_pdp_changed= %s\n",(*i).second.date_pdp_changed.c_str());
		fprintf(fp,"used_gprs= %.2f\n",(*i).second.used_gprs);
		fprintf(fp,"row_id= %s\n",(*i).second.row_id.c_str());
		fprintf(fp,"changed= %.2f\n\n",(*i).second.changed);
	}
}

void churn::print_bill_detail_item_map()
{
	BILL_DETAIL_ITEM_DEF::iterator	i;

	for(i = bill_detail_item_map.begin(); i != bill_detail_item_map.end(); i++)
	{
		fprintf(fp,"-------------------------------------------------------------------\n");
		fprintf(fp,"k_node_id= %.2f\n\n",(*i).first);
		fprintf(fp,"node_id= %.2f\n",(*i).second.node_id);
		fprintf(fp,"value= %.2f\n",(*i).second.value);
		fprintf(fp,"item_code= %s\n\n",(*i).second.item_code.c_str());
	}
}

void churn::print_gprs_pdp_cx_map()
{
	GPRS_PDP_CX_DEF::iterator	i;

	for(i = gprs_pdp_cx_map.begin(); i != gprs_pdp_cx_map.end(); i++)
	{
		fprintf(fp,"-------------------------------------------------------------------");
		fprintf(fp,"k_image_id= %.2f\n",(*i).first.image_id);
		fprintf(fp,"k_connection_id= %.2f\n",(*i).first.connection_id);
		fprintf(fp,"k_pdp_model_id= %s\n\n",(*i).first.pdp_model_id.c_str());

		fprintf(fp,"image_id= %.2f\n",(*i).second.image_id);
		fprintf(fp,"connection_id= %.2f\n",(*i).second.connection_id);
		fprintf(fp,"pdp_model_id= %s\n",(*i).second.pdp_model_id.c_str());
		fprintf(fp,"status= %s|\n\n",(*i).second.status.c_str());
	}
}



	