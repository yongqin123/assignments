/* (1) */
set global general_log='ON';
set global log_output='TABLE';
show variables like 'log_output';

/* (2) */
TRUNCATE TABLE mysql.general_log;

/* (3) execution of A3change2n.sql */

/* (4) */
set global general_log='OFF';

/* (5) */
SELECT event_time, argument FROM mysql.general_log WHERE argument LIKE "%DROP%" OR argument LIKE "%ALTER%" OR argument LIKE "%CREATE%";

/* (6) */
SELECT event_time, argument FROM
(SELECT * FROM 
(SELECT event_time, user_host, thread_id, server_id, command_type, argument, SUBSTRING_INDEX(argument, " ", 1) AS firsttt 
FROM mysql.general_log WHERE argument LIKE "%INSERT%" OR argument LIKE "%DELETE%" OR argument LIKE "%UPDATE%" OR argument LIKE "%SELECT%")d 
JOIN (SELECT firstt, count(firstt) AS counter  FROM (SELECT event_time, user_host, thread_id, server_id, command_type, argument, SUBSTRING_INDEX(argument, " ", 1) AS firstt 
FROM mysql.general_log WHERE argument LIKE "%INSERT%" OR argument LIKE "%DELETE%" OR argument LIKE "%UPDATE%" OR argument LIKE "%SELECT%")b GROUP BY firstt)c 
ON c.firstt = d.firsttt ORDER BY counter DESC)e;


