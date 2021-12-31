
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[24];
};
static const struct sqlcxp sqlfpn =
{
    23,
    "e:\\src\\fup_engine\\db.pc"
};


static unsigned int sqlctx = 592360107;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[11];
   unsigned int   sqhstl[11];
            int   sqhsts[11];
            void  *sqindv[11];
            int   sqinds[11];
   unsigned int   sqharm[11];
   unsigned int   *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned int *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

 static const char *sq0008 = 
"select POLICY_CODE ,THRESHOLD_START ,THRESHOLD_END ,PDP_Model_ID  from PM_FU\
P_POLICY_THRESHOLDS            ";

 static const char *sq0009 = 
"select IMAGE_ID ,GPRS_CONNECTION_ID ,GPRS_STATUS ,CONTRACT_ID ,POLICY_CODE ,\
ACTIVE_PDP_MODEL_ID ,DATE_PDP_CHANGED ,USED_GPRS ,ROW_ID  from FUP_CX_ATTACHME\
NT_V where (EXTENDED_FUP='N' and GPRS_STATUS='C')           ";

 static const char *sq0010 = 
"select NODE_ID ,VALUE ,ITEM_CODE  from BILL_DETAIL_ITEMS_I_V            ";

 static const char *sq0011 = 
"select IMAGE_ID ,CONNECTION_ID ,PDP_MODEL_ID ,STATUS  from GPRS_PDP_CUSTOMER\
S_V            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4146,178,0,0,
5,0,0,1,0,0,32,55,0,0,0,0,0,1,0,
20,0,0,2,0,0,27,71,0,0,4,4,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,5,0,
0,1,10,0,0,1,10,0,0,1,10,0,0,
64,0,0,3,54,0,1,72,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
92,0,0,4,0,0,27,98,0,0,4,4,0,3,6,82,65,84,73,78,71,1,5,0,0,1,10,0,0,1,10,0,0,1,
10,0,0,
129,0,0,5,54,0,1,99,0,0,0,0,0,3,6,82,65,84,73,78,71,
150,0,0,6,0,0,30,108,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
178,0,0,7,0,0,30,114,0,0,0,0,0,3,6,82,65,84,73,78,71,
199,0,0,8,107,0,9,164,0,0,0,0,0,3,6,82,65,84,73,78,71,
220,0,0,8,0,0,13,169,0,0,4,0,0,3,6,82,65,84,73,78,71,2,5,0,0,2,4,0,0,2,4,0,0,2,
5,0,0,
257,0,0,8,0,0,15,201,0,0,0,0,0,3,6,82,65,84,73,78,71,
278,0,0,9,214,0,9,271,0,0,0,0,0,3,6,82,65,84,73,78,71,
299,0,0,9,0,0,13,276,0,0,9,0,0,3,6,82,65,84,73,78,71,2,4,0,0,2,4,0,0,2,5,0,0,2,
4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,5,0,0,
356,0,0,9,0,0,15,315,0,0,0,0,0,3,6,82,65,84,73,78,71,
377,0,0,10,72,0,9,366,0,0,0,0,0,3,6,82,65,84,73,78,71,
398,0,0,10,0,0,13,371,0,0,3,0,0,3,6,82,65,84,73,78,71,2,4,0,0,2,4,0,0,2,5,0,0,
431,0,0,10,0,0,15,406,0,0,0,0,0,3,6,82,65,84,73,78,71,
452,0,0,11,91,0,9,459,0,0,0,0,0,3,6,82,65,84,73,78,71,
473,0,0,11,0,0,13,464,0,0,4,0,0,3,6,82,65,84,73,78,71,2,4,0,0,2,4,0,0,2,5,0,0,
2,5,0,0,
510,0,0,11,0,0,15,497,0,0,0,0,0,3,6,82,65,84,73,78,71,
531,0,0,12,157,0,6,538,0,0,7,7,0,3,6,82,65,84,73,78,71,3,5,0,0,3,5,0,0,3,4,0,0,
3,4,0,0,3,5,0,0,3,5,0,0,3,4,0,0,
580,0,0,13,196,0,6,607,0,0,11,11,0,3,6,82,65,84,73,78,71,3,5,0,0,3,5,0,0,3,4,0,
0,3,4,0,0,3,5,0,0,3,5,0,0,3,4,0,0,3,5,0,0,3,5,0,0,3,5,0,0,3,4,0,0,
645,0,0,14,90,0,5,654,0,0,3,3,0,3,6,82,65,84,73,78,71,1,5,0,0,1,5,0,0,1,5,0,0,
678,0,0,15,0,0,29,666,0,0,0,0,0,3,6,82,65,84,73,78,71,
699,0,0,16,0,0,29,670,0,0,0,0,0,3,6,82,65,84,73,78,71,
720,0,0,17,63,0,4,688,0,0,1,0,0,3,6,82,65,84,73,78,71,2,5,0,0,
};




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <oraca.h>
#include <sqlcpr.h>
#include <sqlda.h>
#include <sqlca.h>


#ifndef ORA_PROC
#include "data_containers.h"
#include <fstream>
#endif


extern	churn	*gsm_churn;
extern  FILE* fp;

#define FETCH_SIZE	5000
#define BUF_LEN	100		


/* EXEC SQL DECLARE CUSTOMER_CARE DATABASE; */ 
 
/* EXEC SQL DECLARE RATING DATABASE; */ 
 

/* EXEC SQL BEGIN DECLARE SECTION; */ 

char *login_cust_care;
char *login_rating;
/* EXEC SQL END DECLARE SECTION; */ 



void sql_error(char *msg)
{
	cout<<"\n"<<msg<<endl;
	sqlca.sqlerrm.sqlerrmc[sqlca.sqlerrm.sqlerrml] = '\0';
	oraca.orastxt.orastxtc[oraca.orastxt.orastxtl] = '\0';
	oraca.orasfnm.orasfnmc[oraca.orasfnm.orasfnml] = '\0';
	cout<<sqlca.sqlerrm.sqlerrmc<<endl;
	cout<<oraca.orastxt.orastxtc<<endl;
	cout<<oraca.oraslnr<<" === "<<oraca.orasfnm.orasfnmc<<endl;
			
	//-- Roll back any pending changes and disconnect from Oracle.
	//EXEC SQL ROLLBACK RELEASE;
	exit(1);
}

void not_found_error(char *msg)
{
    printf("\n%s\n",msg);
   
  //-- Roll back any pending changes and disconnect from Oracle.

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    exit(1);
}



//-- Connect to ORACLE as customer care. 
void db_connect_cust_care(char *in_login)
{
	login_cust_care = in_login;  // a pointer assignment, in_login has the space acclocation

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 


	//ut<<"\nConnecting to ORACLE  as: "<<login_cust_care<<endl;
 	fprintf(fp,"\nConnecting to ORACLE  \n");

    /* EXEC SQL CONNECT :login_cust_care AT CUSTOMER_CARE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)login_cust_care;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	/* EXEC SQL AT CUSTOMER_CARE ALTER SESSION SET NLS_DATE_FORMAT="YYYYMMDDHH24MISS"; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = \"YYYYMMDDHH24MISS\"";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )64;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	fprintf(fp,"Connected  to Database\n\n");

}


//-- Connect to ORACLE as rating. 
void db_connect_rating(char *in_login)
{
	login_rating = in_login;  // a pointer assignment, in_login has the space acclocation

	////////////////////////////////////////////////////////////
	char str[101];
	strcpy(str,login_rating);
	str[strlen(str)] = '\0';
	char delims[] = "/";
	char *result = NULL;
	result = strtok( str, delims );
	////////////////////////////////////////////////////////////


    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 


	fprintf(fp,"\nConnecting to ORACLE  as: %s\n",result);
 	fprintf(fp,"\nConnecting to ORACLE  \n");

    /* EXEC SQL CONNECT :login_rating AT RATING; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )92;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)login_rating;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	/* EXEC SQL AT RATING ALTER SESSION SET NLS_DATE_FORMAT="YYYYMMDDHH24MISS"; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = \"YYYYMMDDHH24MISS\"";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )129;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	fprintf(fp,"Connected  to Database\n\n");

}


void db_disconnect_cust_care()
{
	fprintf(fp,"\nORACLE  customer care database: DISCONNECT\n");
	/* EXEC SQL AT CUSTOMER_CARE COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )150;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
}

void db_disconnect_rating()
{
	fprintf(fp,"\nORACLE  rating database: DISCONNECT\n");
	/* EXEC SQL AT RATING COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )178;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
}

void churn::db_read_pm_fup_policy_thresholds()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct psi_t
	{ 
		char	policy_code[BUF_LEN];
		double 	threshold_start;
		double 	threshold_end;
		char	pdp_model_id[BUF_LEN];
	} *a;

	struct psi_ind
	{ 
 		short	policy_code_ind;
		short	threshold_start_ind;
		short	threshold_end_ind;
		short	pdp_model_id_ind;	
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new psi_t[rows_to_fetch])==NULL)
	{
		fprintf(fp," cant allocate memory pm_fup_policy_thresholds fetch\n");
		exit(0);
	}

 
	/* EXEC SQL 
	AT rating 
	DECLARE  c_fup_policy CURSOR FOR 
	SELECT	POLICY_CODE,						//VARCHAR2(10)     NOT NULL,
			THRESHOLD_START,					//NUMBER(10)	   NOT NULL, -- SIZE IN KB
			THRESHOLD_END,						//NUMBER(10)	   NOT NULL, -- SIZE IN KB
			PDP_Model_ID						//varchar2(15)	   NOT NULL,
	FROM PM_FUP_POLICY_THRESHOLDS; */ 


 
	/* EXEC SQL AT rating  OPEN c_fup_policy; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )199;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT rating FOR :rows_to_fetch FETCH c_fup_policy INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )220;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)a->policy_code;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->policy_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->threshold_start;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->threshold_start_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->threshold_end;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->threshold_end_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->pdp_model_id;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->pdp_model_id_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		fprintf(fp," pm_fup_policy_thresholds=%d \n", rows_before);
		//printf(" pm_fup_policy_thresholds=%d \n", rows_before);

		policy_threshold		p_threshold;
		policy_threshold_key	p_threshold_key;
				
		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			// No null fetches to handle

			p_threshold.init();
			p_threshold_key.init();

			p_threshold.policy_code		= a[i].policy_code;
			p_threshold.threshold_start	= a[i].threshold_start;
			p_threshold.threshold_end	= a[i].threshold_end;
			p_threshold.pdp_model_id	= a[i].pdp_model_id;

			p_threshold_key.policy_code		= a[i].policy_code;
			p_threshold_key.threshold_start	= a[i].threshold_start;
			
			policy_threshold_map.insert(POLICY_THRESHOLD_DEF::value_type(p_threshold_key, p_threshold));
		}
	} 

	/* EXEC SQL AT rating CLOSE c_fup_policy; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )257;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	fprintf(fp,"%d  pm_fup_policy_thresholds data read.\n\n",rows_before);
	printf("%d  pm_fup_policy_thresholds data read.\n\n",rows_before);
}

void churn::db_read_fup_cx_attachment_v()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct psi_t
	{ 
		double	image_id;						// number(10) - NN
		double	gprs_connection_id;				// number(10) - NN
		char	gprs_status[BUF_LEN];			// varchar2(40) - NN
		double	contract_id;					// number(10) - NN
		char	policy_code[BUF_LEN];			// varchar2(10) - NN
		char	active_pdp_model_id[BUF_LEN];	// varchar2(15) - NN
		char	date_pdp_changed[BUF_LEN];		// date
		double	used_gprs;						// number(15,2)
		char	row_id[BUF_LEN];				// rowid
	} *a;

	struct psi_ind
	{ 
 		short	image_id_ind;
		short	gprs_connection_id_ind;
		short	gprs_status_ind;
		short	contract_id_ind;	
		short	policy_code_ind;
		short	active_pdp_model_id_ind;
		short	date_pdp_changed_ind;	
		short	used_gprs_ind;
		short	row_id_ind;		
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new psi_t[rows_to_fetch])==NULL)
	{
		fprintf(fp," cant allocate memory for fup_cx_attachment_v fetch\n");
		exit(0);
	}

 
	/* EXEC SQL 
	AT rating 
	DECLARE  c_fup_cx CURSOR FOR 
	SELECT	IMAGE_ID,						//  NUMBER(10)        NOT NULL,				 
			GPRS_CONNECTION_ID,				//	NUMBER(10)        NOT NULL,
			GPRS_STATUS,					//	VARCHAR2(40)		NOT NULL
			CONTRACT_ID,					//  NUMBER(10)        NOT NULL,
			POLICY_CODE,					//	VARCHAR2(10)	  NOT NULL,
			ACTIVE_PDP_MODEL_ID,			//	varchar2(15)	  NOT NULL,
			DATE_PDP_CHANGED,				//	date,	
			USED_GPRS,						//	number(15,2)
			ROW_ID							//	ROWID
	FROM	FUP_CX_ATTACHMENT_V
	WHERE	EXTENDED_FUP = 'N' //No need to consider because the CX has paid in advance for the extension
	AND GPRS_STATUS = 'C'; */ 


 
	/* EXEC SQL AT rating  OPEN c_fup_cx; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0009;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )278;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT rating FOR :rows_to_fetch FETCH c_fup_cx INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )299;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->image_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->image_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->gprs_connection_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->gprs_connection_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->gprs_status;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->gprs_status_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->contract_id;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->contract_id_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->policy_code;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->policy_code_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->active_pdp_model_id;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->active_pdp_model_id_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->date_pdp_changed;
  sqlstm.sqhstl[6] = (unsigned int  )100;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->date_pdp_changed_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->used_gprs;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->used_gprs_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->row_id;
  sqlstm.sqhstl[8] = (unsigned int  )100;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->row_id_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		fprintf(fp," fup_cx_attachment_v=%d \n", rows_before);
		//printf(" fup_cx_attachment_v=%d \n", rows_before);

		fup_cx_attachment	fc_attachment;
		
		
		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].used_gprs = (a_ind[i].used_gprs_ind < 0) ? 0 : a[i].used_gprs;
			strcpy(a[i].date_pdp_changed,
				  ((a_ind[i].date_pdp_changed_ind < 0) ? "UNDEF":a[i].date_pdp_changed));
			
			
			fc_attachment.init();

			fc_attachment.image_id				= a[i].image_id;
	 		fc_attachment.gprs_connection_id	= a[i].gprs_connection_id;
			fc_attachment.gprs_status			= a[i].gprs_status;
			fc_attachment.contract_id			= a[i].contract_id;
			fc_attachment.policy_code			= a[i].policy_code;
			fc_attachment.active_pdp_model_id	= a[i].active_pdp_model_id;
			fc_attachment.date_pdp_changed		= a[i].date_pdp_changed;
			fc_attachment.used_gprs				= a[i].used_gprs;
			fc_attachment.row_id				= a[i].row_id;
				
			cx_attach_map.insert(CX_ATTACH_DEF::value_type(a[i].image_id, fc_attachment));

			cx_attach_con_id_map.insert(CX_ATTACH_CON_ID_DEF::value_type(a[i].contract_id, fc_attachment));
		}
	} 

	/* EXEC SQL AT rating CLOSE c_fup_cx; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )356;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	fprintf(fp,"%d  fup_cx_attachment_v data read.\n\n",rows_before);
	printf("%d  fup_cx_attachment_v data read.\n\n",rows_before);
}

void churn::db_read_bill_detail_items_i()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct psi_t
	{ 
		double		node_id;				// number(10)
		double		value;					// number(14,6)
		char		item_code[BUF_LEN];		// varchar2(10)
	} *a;

	struct psi_ind
	{ 
 		short	node_id_ind;
		short	value_ind;
		short	item_code_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new psi_t[rows_to_fetch])==NULL)
	{
		fprintf(fp," cant allocate memory for read_bill_detail_items_i fetch\n");
		exit(0);
	}

 
	/* EXEC SQL 
	AT rating 
	DECLARE  c_bill_items CURSOR FOR 
	SELECT	NODE_ID,               // NUMBER (10), 
			VALUE,                 // NUMBER (14,6), 
			ITEM_CODE              // VARCHAR2 (10), 
	//FROM	BILL_DETAIL_ITEMS_I;
	FROM	BILL_DETAIL_ITEMS_I_V; */ 


 
	/* EXEC SQL AT rating  OPEN c_bill_items; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0010;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )377;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT rating FOR :rows_to_fetch FETCH c_bill_items INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )398;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->node_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->node_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->value;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->value_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->item_code;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->item_code_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		fprintf(fp," read_bill_detail_items_i=%d \n", rows_before);
		//printf(" read_bill_detail_items_i=%d \n", rows_before);

		bill_detail_item	bd_item;
		
		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			a[i].node_id = (a_ind[i].node_id_ind < 0) ? 0 : a[i].node_id;
			a[i].value = (a_ind[i].value_ind < 0) ? 0 : a[i].value;
			strcpy(a[i].item_code,
				  ((a_ind[i].item_code_ind < 0) ? "UNDEF":a[i].item_code));
			
			
			//if ( ( strncmp(a[i].conn_type, "VOICEPRE", 8) != 0 ) && ( strncmp(a[i].switch_status, "D", 1) != 0 ) )
			
			if ( strncmp(a[i].item_code, "V_GPRS", 6) == 0 )
			{
				bd_item.init();

				bd_item.node_id		= a[i].node_id;
				bd_item.value		= a[i].value;
				bd_item.item_code	= a[i].item_code;

				bill_detail_item_map.insert(BILL_DETAIL_ITEM_DEF::value_type(a[i].node_id, bd_item));
			}
		}
	} 

	/* EXEC SQL AT rating CLOSE c_bill_items; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )431;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	fprintf(fp,"%d  read_bill_detail_items_i data read.\n\n",rows_before);
	printf("%d  read_bill_detail_items_i data read.\n\n",rows_before);
}

void churn::db_read_gprs_pdp_customers()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct psi_t
	{
		double	image_id;
		double 	connection_id;
		char	pdp_model_id[BUF_LEN];
		char	status[BUF_LEN];
	} *a;

	struct psi_ind
	{ 
 		short	image_id_ind;
		short	connection_id_ind;
		short	pdp_model_id_ind;
		short	status_ind;	
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new psi_t[rows_to_fetch])==NULL)
	{
		fprintf(fp," cant allocate memory for gprs_pdp_customers fetch\n");
		exit(0);
	}

 
	/* EXEC SQL 
	AT rating 
	DECLARE  c_cx CURSOR FOR 
	SELECT	IMAGE_ID, 			// N10	- NN
			CONNECTION_ID,		// N10	- NN 
			PDP_MODEL_ID, 		// VC15	- NN
			STATUS				// VC2	- NN
	//FROM	GPRS_PDP_CUSTOMERS;	
	FROM	GPRS_PDP_CUSTOMERS_V; */ 

 
	/* EXEC SQL AT rating  OPEN c_cx; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )452;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT rating FOR :rows_to_fetch FETCH c_cx INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )473;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->image_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->image_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->connection_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->connection_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->pdp_model_id;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->pdp_model_id_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->status;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->status_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		fprintf(fp," gprs_pdp_customers=%d \n", rows_before);

		gprs_pdp_customer		gp_customer;
		gprs_pdp_customer_key	gp_customer_key;
				
		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			// No null fetches

			gp_customer.init();
			gp_customer_key.init();

			gp_customer.image_id		= a[i].image_id;
			gp_customer.connection_id	= a[i].connection_id;
			gp_customer.pdp_model_id	= a[i].pdp_model_id;
			gp_customer.status			= a[i].status;

			gp_customer_key.image_id		= a[i].image_id;
			gp_customer_key.connection_id	= a[i].connection_id;
			gp_customer_key.pdp_model_id	= a[i].pdp_model_id;
			
			gprs_pdp_cx_map.insert(GPRS_PDP_CX_DEF::value_type(gp_customer_key, gp_customer));
		}
	} 

	/* EXEC SQL AT rating CLOSE c_cx; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )510;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	fprintf(fp,"%d  gprs_pdp_customers data read.\n\n",rows_before);
}

bool churn::activate_deactivate_pdp(string pdp_model_found, double image_id, double connection_id, string action)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	char	l_pdp_model_found[15];		// varchar2(15)			
	double	l_image_id;
	double	l_connection_id;
	char	l_reason_id[5];
	char	l_action[5];
	//char	l_group_id[2];
	double	l_group_id;				
	char	return_value[200];
	
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(l_pdp_model_found, pdp_model_found.c_str());
	l_image_id		= image_id;
	l_connection_id	= connection_id;
	strcpy(l_reason_id, "FUP");
	l_reason_id[3] = '\0';
	strcpy(l_action, action.c_str());
	l_group_id	= connection_id;	
	//strcpy(l_group_id, "");
	//l_group_id[0] = '\0';
	//l_reason_id[0] = '\0';
	return_value[0] = '\0';

	fprintf(fp,"l_pdp_model_found = %s|\n",l_pdp_model_found);
	fprintf(fp,"l_connection_id = %.2f\n",l_connection_id);
	fprintf(fp,"l_image_id = %.2f\n",l_image_id);
	fprintf(fp,"l_reason_id = %s|\n",l_reason_id);
	fprintf(fp,"l_action = %s|\n",l_action);
	fprintf(fp,"l_group_id = %.2f\n",l_group_id);
	fprintf(fp,"return_value = %s|\n",return_value);


	/* EXEC SQL
	AT rating
	EXECUTE
	BEGIN
	:return_value := APN.ACTIVATE_DEACTIVATE_PDP(:l_pdp_model_found,:l_image_id,:l_connection_id,:l_reason_id,:l_action,:l_group_id);
	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :return_value := APN . ACTIVATE_DEACTIVATE_PDP ( :l_pd\
p_model_found , :l_image_id , :l_connection_id , :l_reason_id , :l_action , :l\
_group_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )531;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)return_value;
 sqlstm.sqhstl[0] = (unsigned int  )200;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)l_pdp_model_found;
 sqlstm.sqhstl[1] = (unsigned int  )15;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&l_image_id;
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&l_connection_id;
 sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)l_reason_id;
 sqlstm.sqhstl[4] = (unsigned int  )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)l_action;
 sqlstm.sqhstl[5] = (unsigned int  )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&l_group_id;
 sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	fprintf(fp,"Return_value - ACTIVATE_DEACTIVATE_PDP = %s\n",return_value);

	/*
	if (return_value == 1)
		return true;
	else return false;
	*/
	return true;
}

bool churn::install_pdp(string pdp_model_found, double image_id, double connection_id, string sys_date)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	char	l_pdp_model_found[15];		// varchar2(15)			
	double	l_image_id;
	double	l_connection_id;
	char	l_pkg_code[2];
	char	l_apn_id[2];
	float	l_rental;
	char	l_sys_date[20];
	char	l_end_date[2];
	char	l_insert[2];
	double	l_group_id;				
	char	return_value[250];
	
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(l_pdp_model_found, pdp_model_found.c_str());
	l_image_id		= image_id;
	l_connection_id	= connection_id;
	//strcpy(l_pkg_code, "");
	l_pkg_code[0] = '\0';
	//strcpy(l_apn_id, "");
	l_apn_id[0] = '\0';
	l_rental		= 0;
	//cout << "sys_date =" << sys_date << endl;
	strcpy(l_sys_date, sys_date.c_str());
	//strcpy(l_sys_date, "20080207000000");
	l_sys_date[14]='\0';
	//strcpy(l_end_date, "");
	l_end_date[0] = '\0';
	strcpy(l_insert, "Y");
	l_insert[1]='\0';
	//strcpy(l_group_id, "");
	l_group_id = connection_id;
	return_value[0] = '\0';

	fprintf(fp,"l_pdp_model_found = %s|\n",l_pdp_model_found);
	fprintf(fp,"l_image_id = %.2f\n",l_image_id);
	fprintf(fp,"l_connection_id = %.2f\n",l_connection_id);
	fprintf(fp,"l_pkg_code = %s|\n",l_pkg_code);
	fprintf(fp,"l_apn_id = %s|\n",l_apn_id);
	fprintf(fp,"l_sys_date = %s|\n",l_sys_date);
	fprintf(fp,"l_end_date = %s|\n",l_end_date);
	fprintf(fp,"l_insert = %s|\n",l_insert);
	fprintf(fp,"l_group_id = %.2f\n",l_group_id);
	fprintf(fp,"return_value = %s|\n",return_value);



	/* EXEC SQL
	AT rating
	EXECUTE
	BEGIN
	:return_value := APN.INSTALL_PDP(:l_pdp_model_found,:l_image_id,:l_connection_id,:l_pkg_code,:l_apn_id,:l_rental,:l_sys_date,:l_end_date,:l_insert,:l_group_id);
	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :return_value := APN . INSTALL_PDP ( :l_pdp_model_foun\
d , :l_image_id , :l_connection_id , :l_pkg_code , :l_apn_id , :l_rental , :l_\
sys_date , :l_end_date , :l_insert , :l_group_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )580;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)return_value;
 sqlstm.sqhstl[0] = (unsigned int  )250;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)l_pdp_model_found;
 sqlstm.sqhstl[1] = (unsigned int  )15;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&l_image_id;
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&l_connection_id;
 sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)l_pkg_code;
 sqlstm.sqhstl[4] = (unsigned int  )2;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)l_apn_id;
 sqlstm.sqhstl[5] = (unsigned int  )2;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)&l_rental;
 sqlstm.sqhstl[6] = (unsigned int  )sizeof(float);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)l_sys_date;
 sqlstm.sqhstl[7] = (unsigned int  )20;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)l_end_date;
 sqlstm.sqhstl[8] = (unsigned int  )2;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)l_insert;
 sqlstm.sqhstl[9] = (unsigned int  )2;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         void  *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)&l_group_id;
 sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         void  *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	fprintf(fp,"Return_value - Install PDP = %s\n",return_value);

	/*
	if (return_value == 1)
		return true;
	else return false;
	*/
	
	return true;
}

void churn::db_update_fup_cx_attachment()
{
	fprintf(fp,"\n updating fup_cx_attachment \n ");

	fprintf(fp,"rows to update = %d",cx_attach_con_id_changed_map.size());

	int	rows_inserted = 0;

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		char	row_id[BUF_LEN];
		char	active_pdp_model_id[BUF_LEN];	
		char	date_pdp_changed[BUF_LEN];		
		
	/* EXEC SQL END DECLARE SECTION; */ 


	for(CX_ATTACH_CON_ID_DEF::iterator i_db_insert =cx_attach_con_id_changed_map.begin(); i_db_insert!=cx_attach_con_id_changed_map.end(); i_db_insert++)
	{
		strcpy(row_id,					( (*i_db_insert).second.row_id).c_str() );
		strcpy(active_pdp_model_id,		( (*i_db_insert).second.active_pdp_model_id).c_str() );
		//strcpy(date_pdp_changed,		( (*i_db_insert).second.date_pdp_changed).c_str() );
		strcpy(date_pdp_changed,		sys_date );
		//strcpy(date_pdp_changed,		"20070202000000" );

		fprintf(fp,"row_id = %s|\n",row_id);
		fprintf(fp,"active_pdp_model_id = %s|\n",active_pdp_model_id);
		fprintf(fp,"date_pdp_changed = %s|\n",date_pdp_changed);
		
		/* EXEC SQL 
		AT rating 
		UPDATE  FUP_CX_ATTACHMENT
		SET
			ACTIVE_PDP_MODEL_ID		= :active_pdp_model_id, 
			DATE_PDP_CHANGED		= :date_pdp_changed 
		WHERE
		  ROWID = :row_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update FUP_CX_ATTACHMENT  set ACTIVE_PDP_MODEL_ID=:b0,DATE_\
PDP_CHANGED=:b1 where ROWID=:b2";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )645;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)active_pdp_model_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)date_pdp_changed;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)row_id;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



		rows_inserted++;
		if( !(rows_inserted%500))
		{
			/* EXEC SQL AT rating  COMMIT; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 11;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )678;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


		}
	}

	/* EXEC SQL AT rating  COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )699;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	fprintf(fp,"fup_cx_attachment updated ");
}




void churn::get_db_sysdate()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		 char	br_system_date[20];	

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL WHENEVER NOT FOUND DO not_found_error("not_found_error in get_db_sysdate()"); */ 
 

	/* EXEC SQL 
	AT rating
	SELECT	to_char(sysdate,'YYYYMMDDHH24MISS')
	INTO	:br_system_date
	FROM	DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char(sysdate,'YYYYMMDDHH24MISS') into :b0  from DU\
AL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )720;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("not_found_error in get_db_sysdate()");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	sys_date[0] = '\0';
	strcpy(sys_date, br_system_date);
	sys_date[14] = '\0';

	fprintf(fp,"sysdate = %s|\n",sys_date);
	//transition	= true;
}

