# KAAVAL – Holidays Table Design

## 1. Table Name

`holidays`

## 2. Purpose

The holidays table stores school holidays and other non-working days used by the KAAVAL attendance system.

## 3. Table Columns

| Column Name | Data Type | Constraint | Purpose |
|---|---|---|---|
| holiday_id | BIGINT | PRIMARY KEY, IDENTITY | Unique holiday ID |
| holiday_name | VARCHAR(120) | NOT NULL | Holiday name |
| holiday_date | DATE | NOT NULL | Holiday date |
| holiday_type | VARCHAR(30) | NOT NULL | Holiday category |
| description | TEXT | NULL allowed | Additional details |
| is_active | BOOLEAN | DEFAULT TRUE | Active status |
| created_at | TIMESTAMPTZ | DEFAULT CURRENT_TIMESTAMP | Record creation time |

## 4. Column Details

### 4.1 holiday_id
- Unique ID for each holiday.
- Primary Key.
- Automatically generated.

### 4.2 holiday_name
- Stores the holiday name.
- Cannot be empty.

### 4.3 holiday_date
- Stores the holiday date.
- Uses DATE format.

### 4.4 holiday_type
- Stores the holiday category.
- Examples: PUBLIC, SCHOOL, FESTIVAL.

### 4.5 description
- Stores additional holiday information.
- Can be NULL.

### 4.6 is_active
- TRUE means the holiday is active.
- FALSE means it is inactive.
- Default TRUE.

### 4.7 created_at
- Records when the holiday was created.
- Default CURRENT_TIMESTAMP.

## 5. Constraints

- holiday_id must be unique.
- holiday_name cannot be empty.
- holiday_date cannot be empty.
- Duplicate active holiday dates should be reviewed before saving.
- Holiday changes must preserve historical attendance records.

## 6. Relationships

The holidays table is used by attendance and reporting logic to identify non-working days.

## 7. Example Data (Dummy Data)

| holiday_id | holiday_name | holiday_date | holiday_type |
|---|---|---|---|
| 1 | Gandhi Jayanti | 2026-10-02 | PUBLIC |
| 2 | School Holiday | 2026-11-15 | SCHOOL |

These are sample records only.

## 8. Management Rules

- Only authorized administrators can add or edit holidays.
- Holidays must be checked before monthly attendance calculations.
- Sundays and other weekly holidays must follow the school's approved calendar.
- Do not automatically assume every Sunday or public holiday is a school holiday without checking the school calendar.

## 9. Status

Holidays Table Design: Completed after review.
