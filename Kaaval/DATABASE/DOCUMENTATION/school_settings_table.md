# KAAVAL – School Settings Table Design

## 1. Table Name

`school_settings`

## 2. Purpose

The school_settings table stores configurable school and attendance settings used by the KAAVAL system.

## 3. Table Columns

| Column Name | Data Type | Constraint | Purpose |
|---|---|---|---|
| setting_id | BIGINT | PRIMARY KEY, IDENTITY | Unique setting ID |
| setting_key | VARCHAR(100) | UNIQUE, NOT NULL | Setting identifier |
| setting_value | TEXT | NOT NULL | Setting value |
| description | TEXT | NULL allowed | Setting explanation |
| updated_at | TIMESTAMPTZ | DEFAULT CURRENT_TIMESTAMP | Last update time |
| updated_by | BIGINT | FOREIGN KEY, NULL allowed | Admin user reference |

## 4. Column Details

### 4.1 setting_id
- Unique ID for each setting.
- Primary Key.
- Automatically generated.

### 4.2 setting_key
- Stores the setting name.
- Must be unique.
- Examples: SCHOOL_NAME, LATE_CUTOFF_TIME, TIME_ZONE.

### 4.3 setting_value
- Stores the setting value.
- Cannot be empty.
- Example: 09:15 for a time setting.

### 4.4 description
- Explains the purpose of the setting.
- Can be NULL.

### 4.5 updated_at
- Stores the last update timestamp.
- Automatically updated when a setting changes through the backend.

### 4.6 updated_by
- References the administrator account that changed the setting.
- Foreign Key referencing users.user_id.
- Can be NULL for initial system settings.

## 5. Example Settings (Dummy Data)

| setting_key | setting_value |
|---|---|
| SCHOOL_NAME | Demo School |
| SCHOOL_TIME_ZONE | Asia/Kolkata |
| LATE_CUTOFF_TIME | 09:15 |
| SMS_ENABLED | false |
| WEEKLY_HOLIDAY | SUNDAY |

## 6. Management Rules

- Only authorized administrators can change school settings.
- Validate each setting according to its expected format.
- Do not allow unauthorized users to change attendance rules.
- Record who changed important settings.
- Validate settings on the server before applying them to attendance processing.

## 7. Security Rules

- Do not expose private system configuration through public APIs.
- Protect administrator-only settings.
- Do not store passwords or API secrets as ordinary setting values.

## 8. Status

School Settings Table Design: Completed after review.