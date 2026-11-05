

\# B15 - Teacher Classes Table



\## 1. Purpose

This table connects teachers with multiple sections.



\## 2. Table Name

teacher\_classes



\## 3. Columns



| Column | Data Type | Constraints |

|---|---|---|

| teacher\_class\_id | BIGINT | PRIMARY KEY, GENERATED ALWAYS AS IDENTITY |

| teacher\_id | BIGINT | NOT NULL, FOREIGN KEY |

| section\_id | BIGINT | NOT NULL, FOREIGN KEY |

| created\_at | TIMESTAMPTZ | DEFAULT CURRENT\_TIMESTAMP |



\## 4. Relationships



\- teacher\_id references teachers(teacher\_id).

\- section\_id references sections(section\_id).

\- One teacher can be assigned to multiple sections.

\- One section can have multiple teachers.



\## 5. Unique Constraint



UNIQUE (teacher\_id, section\_id)



This prevents duplicate assignments.



\## 6. Status



B15 table design documented.



SQL implementation and database verification are separate steps.



