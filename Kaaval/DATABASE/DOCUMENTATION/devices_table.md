# KAAVAL – Devices Table Design

## 1. Table Name

`devices`

## 2. Purpose

The devices table stores information about registered KAAVAL attendance devices such as ESP32 fingerprint attendance machines.

## 3. Table Columns

| Column Name | Data Type | Constraint | Purpose |
|---|---|---|---|
| device_id | BIGINT | PRIMARY KEY, IDENTITY | Unique device ID |
| device_code | VARCHAR(50) | UNIQUE, NOT NULL | Device identification code |
| device_name | VARCHAR(100) | NOT NULL | Device name |
| device_secret_hash | VARCHAR(255) | NOT NULL | Authentication secret hash |
| location | VARCHAR(120) | NULL allowed | Device installation location |
| is_active | BOOLEAN | DEFAULT TRUE | Device active status |
| last_seen_at | TIMESTAMPTZ | NULL allowed | Last connection time |
| created_at | TIMESTAMPTZ | DEFAULT CURRENT_TIMESTAMP | Record creation time |

## 4. Column Details

### 4.1 device_id
- Unique identification number for each device.
- Primary Key.
- Automatically generated.

### 4.2 device_code
- Stores the unique device identification code.
- Must be unique.
- Cannot be empty.

### 4.3 device_name
- Stores the readable device name.
- Maximum length: 100 characters.
- Cannot be empty.

### 4.4 device_secret_hash
- Stores the securely protected device authentication secret.
- Must not contain the plain-text secret.
- Used by the server to authenticate registered devices.
- Authentication and secret rotation procedures must be designed securely.

### 4.5 location
- Stores the device installation location.
- Example: Main Gate or School Block B.
- Can be NULL if not assigned.

### 4.6 is_active
- TRUE means the device is active.
- FALSE means the device is disabled.
- Default value is TRUE.

### 4.7 last_seen_at
- Records the last successful device communication time.
- Uses TIMESTAMPTZ.
- Can be NULL before the first successful connection.

### 4.8 created_at
- Records when the device was registered.
- Default value is CURRENT_TIMESTAMP.

## 5. Constraints

- device_id must be unique.
- device_code must be unique.
- device_name cannot be empty.
- Only registered and active devices can submit attendance events.
- Device authentication must be checked by the backend.

## 6. Relationships

- devices.device_id connects to attendance.device_id.
- One device can generate many attendance records.
- One device can have multiple synchronization events recorded in sync_records.
- Device management is controlled by authorized administrators.

## 7. Device Management Rules

- Each KAAVAL device must have a unique device_code.
- Administrators can register or deactivate devices.
- Inactive devices must not submit new attendance records.
- The server should update last_seen_at after successful communication.
- Device identity must be validated before accepting attendance events.

## 8. Security Rules

- Never store plain-text device secrets in the database.
- Never expose device secrets through dashboards or APIs.
- Do not store secrets in public GitHub repositories.
- Use secure device authentication.
- Use HTTPS for remote communication.
- Provide a secure secret rotation and revocation procedure.
- Use dummy device information during development.

## 9. Example Record (Dummy Data)

| device_id | device_code | device_name | location | is_active |
|---|---|---|---|---|
| 1 | KAAVAL-ESP32-001 | Main Gate Device | Main Gate | TRUE |

This is sample data only. Authentication secrets are intentionally omitted.

## 10. Status

Devices Table Design: Completed after review.