/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Human Resources (HR) database						*/
/* Created by Janusz R. Getta, 8 November 2016 from Oracle's HR sample database */
/* 	      	     	       	 	       	    	     	 	      	*/
/* dbdrop.sql script for laboratories and assignments in CSIT115, Autumn 2017	*/
/* dbdrop.sql script drops all tables in a sample database	  	 	*/
/*										*/
/* To create all tables run a script dbcreate.sql				*/
/* To load sample data run a script dbload.sql					*/
/*										*/
ALTER TABLE DEPARTMENT DROP FOREIGN KEY DEPARTMENT_FK2;
DROP TABLE JOBHISTORY;
DROP TABLE EMPLOYEE;
DROP TABLE JOB;
DROP TABLE DEPARTMENT;
DROP TABLE LOCATION;
DROP TABLE COUNTRY;
DROP TABLE REGION;
/*										*/
/* End of dbdrop.sql script							*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
