SET ECHO ON
SPOOL dbdrop

connect tpchr

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* The relational tables of TPC H benchmark database				 */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

DROP TABLE LINEITEM cascade constraint PURGE;
DROP TABLE ORDERS cascade constraint PURGE;
DROP TABLE CUSTOMER cascade constraint PURGE;
DROP TABLE PARTSUPP cascade constraint PURGE;
DROP TABLE SUPPLIER cascade constraint PURGE;
DROP TABLE PART cascade constraint PURGE;
DROP TABLE NATION cascade constraint PURGE;
DROP TABLE REGION cascade constraint PURGE

disconnect

SPOOL OFF
