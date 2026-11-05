

\# B17 - Database Indexing Strategy



\## 1. Purpose



Indexes improve database search and query performance.



\## 2. Student Table Indexes



Potential indexes:



\- students(admission\_number)

\- students(fingerprint\_id)

\- students(section\_id)



\## 3. Attendance Table Indexes



Potential indexes:



\- attendance(student\_id)

\- attendance(attendance\_date)

\- attendance(student\_id, attendance\_date)



\## 4. Teacher Classes Table Indexes



Potential indexes:



\- teacher\_classes(teacher\_id)

\- teacher\_classes(section\_id)



The UNIQUE constraint on

(teacher\_id, section\_id) also creates a unique index

in PostgreSQL.



\## 5. User Table Indexes



Potential indexes:



\- users(username)



Username should also have an appropriate UNIQUE constraint.



\## 6. Indexing Rules



\- Index frequently searched columns.

\- Avoid unnecessary indexes.

\- Indexes improve reads but add storage and write overhead.

\- Review actual query patterns before creating indexes.

\- Use EXPLAIN ANALYZE to inspect query performance.



\## 7. Important Note



Confirm actual table and column names before

implementing indexes in PostgreSQL.



Do not create duplicate indexes where an existing

PRIMARY KEY or UNIQUE constraint already provides one.



\## 8. Status



B17 - Database indexing strategy documented.



Actual index creation and performance testing

will happen during SQL implementation.



