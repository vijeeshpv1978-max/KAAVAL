# KAAVAL – SMS Notifications Table Design

## 1. Table Name

`sms_notifications`

## 2. Purpose

The sms_notifications table stores SMS notification records related to student attendance and other approved school notifications.

## 3. Table Columns

| Column Name | Data Type | Constraint | Purpose |
|---|---|---|---|
| sms_id | BIGINT | PRIMARY KEY, IDENTITY | Unique SMS ID |
| parent_id | BIGINT | FOREIGN KEY, NOT NULL | Recipient parent |
| student_id | BIGINT | FOREIGN KEY, NOT NULL | Related student |
| attendance_id | BIGINT | FOREIGN KEY, NULL allowed | Related attendance |
| message_type | VARCHAR(30) | NOT NULL | Notification category |
| message_text | TEXT | NOT NULL | Message content |
| delivery_status | VARCHAR(20) | DEFAULT PENDING | Delivery status |
| provider_message_id | VARCHAR(100) | NULL allowed | Provider reference |
| created_at | TIMESTAMPTZ | DEFAULT CURRENT_TIMESTAMP | Record creation time |
| sent_at | TIMESTAMPTZ | NULL allowed | Sending time |

## 4. Column Details

### 4.1 sms_id
- Unique ID for each SMS record.
- Primary Key.
- Automatically generated.

### 4.2 parent_id
- Identifies the recipient parent.
- Foreign Key referencing parents.parent_id.

### 4.3 student_id
- Identifies the student related to the notification.
- Foreign Key referencing students.student_id.

### 4.4 attendance_id
- Connects the notification to an attendance record.
- Foreign Key referencing attendance.attendance_id.
- Can be NULL for non-attendance notifications.

### 4.5 message_type
- Stores the notification category.
- Examples: ATTENDANCE, LATE.

### 4.6 message_text
- Stores the notification message.
- Must not be empty.

### 4.7 delivery_status
- Stores the SMS processing status.
- Initial values: PENDING, SENT, FAILED, DELIVERED.
- Default: PENDING.

### 4.8 provider_message_id
- Stores the SMS provider reference.
- Can be NULL if not yet provided.

### 4.9 created_at
- Records when the SMS record was created.

### 4.10 sent_at
- Records when the SMS was submitted to the provider.
- Can be NULL before sending.

## 5. Relationships

- parent_id references parents.parent_id.
- student_id references students.student_id.
- attendance_id references attendance.attendance_id.
- One parent can receive multiple notifications.
- One attendance record can be associated with multiple parent notifications.

## 6. Security Rules

- Only authorized systems can create notification records.
- Parents must receive notifications only for their linked children.
- Protect phone numbers and message content.
- Do not expose SMS provider credentials.
- Avoid storing unnecessary sensitive information in messages.
- Follow applicable school consent and communication policies.

## 7. Delivery Rules

- Create a notification record before attempting delivery.
- Update delivery_status based on provider response.
- SENT does not automatically mean DELIVERED.
- Use provider callbacks or delivery reports where supported.
- Failed messages may be retried according to controlled retry rules.

## 8. Status

SMS Notifications Table Design: Completed after review.