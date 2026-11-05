

\# B16 - Primary Keys and Foreign Keys



\## 1. Purpose



This document defines Primary Keys and Foreign Keys

for the KAAVAL PostgreSQL database.



\## 2. Primary Key



A Primary Key uniquely identifies each record in a table.



Requirements:

\- Must contain unique values.

\- Cannot contain NULL values.

\- Each table should have a suitable Primary Key.



Examples:

\- students.student\_id

\- teachers.teacher\_id

\- parents.parent\_id

\- sections.section\_id

\- attendance.attendance\_id

\- devices.device\_id



\## 3. Foreign Key



A Foreign Key connects one table to another table.



Examples:



| Table | Foreign Key | References |

|---|---|---|

| students | section\_id | sections(section\_id) |

| student\_parents | student\_id | students(student\_id) |

| student\_parents | parent\_id | parents(parent\_id) |

| teacher\_classes | teacher\_id | teachers(teacher\_id) |

| teacher\_classes | section\_id | sections(section\_id) |

| attendance | student\_id | students(student\_id) |



These references must match the actual table definitions

before SQL implementation.



\## 4. Unique Constraints



Important unique constraints:



\- students.admission\_number

\- users.username

\- teacher\_classes(teacher\_id, section\_id)



Confirm the final column names and requirements

against the database architecture before implementation.



\## 5. NOT NULL Constraints



Required fields should use NOT NULL.



Examples:

\- students.full\_name

\- students.admission\_number

\- teacher\_classes.teacher\_id

\- teacher\_classes.section\_id



\## 6. Referential Integrity



Foreign Keys must prevent invalid references.



A child record must not refer to a parent record

that does not exist.



Deletion and update rules must be selected carefully.

Do not delete attendance history accidentally.



\## 7. Security and Data Integrity



\- Use appropriate constraints.

\- Prevent duplicate records.

\- Validate data on the backend.

\- Protect student and parent information.

\- Use dummy data during development.



\## 8. Status



B16 - Primary and Foreign Key documentation prepared.



Actual PostgreSQL constraints must be implemented

and tested in a later SQL implementation stage.



