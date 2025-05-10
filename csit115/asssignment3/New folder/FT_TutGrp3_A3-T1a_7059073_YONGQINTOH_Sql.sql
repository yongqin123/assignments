/* task 1 part A q1*/
CREATE USER yqt817_1 IDENTIFIED BY 'yqt817_1';
CREATE USER yqt817_2 IDENTIFIED BY 'yqt817_2';
CREATE USER yqt817_3 IDENTIFIED BY 'yqt817_3';

/* task 1 part A q2 */
GRANT INSERT, UPDATE, DELETE, SELECT, ALTER, DROP ON yqt817.*  TO yqt817_1;

/* task 1 part A q3 */
GRANT CREATE VIEW, SELECT ON yqt817.BOOK TO yqt817_2;
GRANT CREATE VIEW, SELECT ON yqt817.AUTHOR TO yqt817_2;

/* task 1 part A q4 */
ALTER USER yqt817_3 WITH MAX_QUERIES_PER_HOUR 100;
ALTER USER yqt817_3 WITH MAX_UPDATES_PER_HOUR 10;

/* task 1 part A q5 */
ALTER USER yqt817_2 PASSWORD EXPIRE;

/* task 1 part A q6 */
SELECT user, db, insert_priv, update_priv, delete_priv, select_priv, alter_priv, drop_priv FROM mysql.db where db='yqt817';
SELECT user, db, table_name, table_priv FROM mysql.tables_priv where user='yqt817_2';
select User, max_questions, max_updates FROM mysql.user WHERE User in ('yqt817_3');
select user, password_expired  from mysql.user where user = 'yqt817_2';
