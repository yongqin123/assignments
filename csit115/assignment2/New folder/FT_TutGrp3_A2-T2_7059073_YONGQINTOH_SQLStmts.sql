/* Assn2, Task2, Qn (1) */ 
SELECT EMPLOYEE.employee_id, EMPLOYEE.first_name, EMPLOYEE.last_name, EMPLOYEE.job_title, EMPLOYEE.email FROM EMPLOYEE
WHERE EMPLOYEE.department_name IN
(SELECT DEPARTMENT.department_name FROM DEPARTMENT 
WHERE DEPARTMENT.country_name IN (SELECT country_name FROM COUNTRY WHERE region_name = "Asia"));

/* Assn2, Task2, Qn (2) */ 
SELECT EMPLOYEE.employee_id, EMPLOYEE.first_name, EMPLOYEE.last_name, EMPLOYEE.job_title, EMPLOYEE.supervisor_id FROM EMPLOYEE
JOIN
(SELECT * FROM
(SELECT employee_id, start_date, end_date, department_name, timestampdiff(month, JOBHISTORY.start_date, JOBHISTORY.end_date) AS difference FROM JOBHISTORY
WHERE (department_name = "Information Technology"))a
WHERE difference>=36)b
ON b.employee_id = EMPLOYEE.employee_id;

/* Assn2, Task2, Qn (3) */ 
SELECT * FROM
(SELECT a.employee_id, a.first_name, a.last_name, a.hire_date, a.salary, COUNT(*)total_employees FROM
(SELECT employee_id, first_name, last_name, hire_date, salary FROM EMPLOYEE
WHERE EMPLOYEE.employee_id IN (SELECT DISTINCT supervisor_id FROM EMPLOYEE))a
JOIN EMPLOYEE
ON a.employee_id = EMPLOYEE.supervisor_id
GROUP BY a.employee_id)b 
WHERE total_employees >= 8
;

/* Assn2, Task2, Qn (4) */ 
UPDATE EMPLOYEE SET supervisor_id = 110 WHERE supervisor_id = 114;
UPDATE DEPARTMENT SET manager_id = 110 WHERE manager_id = 114;
DELETE FROM JOBHISTORY WHERE employee_id=114;
DELETE FROM EMPLOYEE WHERE employee_id=114;

/* Assn2, Task2, Qn (5) */ 
INSERT INTO JOB VALUES ("VIP Customer Relations",6000,18000);
INSERT INTO EMPLOYEE VALUES (888,"Pamela","Anderson","pam.anderson",null, str_to_date("18/10/2018","%d/%m/%Y"), "VIP Customer Relations",8880, null,204, "Public Relations");
