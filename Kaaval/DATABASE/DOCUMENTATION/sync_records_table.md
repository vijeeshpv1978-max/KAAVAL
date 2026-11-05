# KAAVAL – Offline Sync Records Table Design

## 1. Table Name

`sync_records`

## 2. Purpose

The sync_records table stores information about attendance events received from KAAVAL devices, including offline synchronization and processing status.

## 3. Table Columns

| Column Name | Data Type | Constraint | Purpose |
|---|---|---|---|
| sync_id | BIGINT | PRIMARY KEY, IDENTITY | Unique sync record ID |
| device_id | BIGINT | FOREIGN KEY, NOT NULL | Device reference |
| event_id | UUID | UNIQUE, NOT NULL | Unique event identifier |
| sync_status | VARCHAR(20) | NOT NULL | Synchronization status |
| retry_count | INTEGER | DEFAULT 0 | Number of retries |
| received_at | TIMESTAMPTZ | DEFAULT CURRENT_TIMESTAMP | Server received time |
| processed_at | TIMESTAMPTZ | NULL allowed | Processing completion time |
| error_message | TEXT | NULL allowed | Error information |

## 4. Column Details

### 4.1 sync_id
- Unique ID for each synchronization record.
- Primary Key.
- Automatically generated.

### 4.2 device_id
- Identifies the device that submitted the event.
- Foreign Key referencing devices.device_id.

### 4.3 event_id
- Unique identifier for the submitted attendance event.
- Uses UUID.
- Must be unique to prevent duplicate processing.

### 4.4 sync_status
- Stores the synchronization status.
- Initial values: RECEIVED, PROCESSED, FAILED.
- Cannot be empty.

### 4.5 retry_count
- Stores the number of processing retries.
- Default value is 0.
- Must not be negative.

### 4.6 received_at
- Records when the server received the event.
- Default CURRENT_TIMESTAMP.

### 4.7 processed_at
- Records when processing was completed.
- Can be NULL before processing.

### 4.8 error_message
- Stores non-sensitive processing error information.
- Can be NULL.

## 5. Relationships

- device_id references devices.device_id.
- event_id identifies the same event used by the attendance processing system.
- Synchronization records are associated with attendance events.

## 6. Synchronization Rules

1. Device creates a unique event_id for an attendance event.
2. Device stores the event locally until server acknowledgement.
3. Server authenticates the device.
4. Server checks whether event_id has already been processed.
5. Server validates the attendance event.
6. Server records the processing result.
7. Device marks the event synchronized only after receiving acknowledgement.
8. Duplicate events must not create duplicate attendance records.

## 7. Security Rules

- Only authenticated devices can submit synchronization events.
- Reject events from inactive devices.
- Do not store unnecessary student or parent personal data in synchronization logs.
- Do not expose device authentication secrets.
- Protect synchronization endpoints from unauthorized access.

## 8. Status

Offline Sync Records Table Design: Completed after review.