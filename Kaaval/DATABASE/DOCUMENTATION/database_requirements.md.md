```markdown
# KAAVAL – Database Requirements

## 1. Project Information
- **Project Name:** KAAVAL
- **Database:** PostgreSQL
- **Purpose:** School fingerprint attendance management

## 2. Student Information
- Student ID
- Admission Number
- Student Name
- Class
- Section
- Fingerprint ID
- Account Status

## 3. Teacher Information
- Teacher ID
- Teacher Name
- Assigned Classes
- Account Status

## 4. Parent Information
- Parent ID
- Parent Name
- Contact Number
- Linked Student

## 5. Attendance Information
- Attendance ID
- Student ID
- Date
- Check-in Time
- Attendance Status
- Device ID

## 6. User Roles
- Admin
- Teacher
- Parent

## 7. School Settings
- School Name
- School Start Time
- Late Cutoff Time
- Timezone

## 8. Additional Features
- Holiday Management
- SMS Notification Records
- Offline Attendance Sync
- Attendance Reports
- Device Management

## 9. Security Requirements
- Password Hashing
- Role-based Permissions
- Device Authentication
- Restricted Parent Access
- Secure Database Backup

## 10. Important Rules
- Do not store plain-text passwords.
- Prevent duplicate attendance records.
- Parents can access only their linked children.
- Use fictional data during development.
- Collect only information required for attendance.
```
