-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Crime Scene Reports that Math The Day
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND year = 2021
AND street = "Humphrey Street";

-- Interview on the particular day and it is know that they mention bakery in it.
SELECT transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE "%bakery%";

-- One of them said look at the security cam in 10 mins.
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name
FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.month = 7
AND bakery_security_logs.year = 2021
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25
AND bakery_security_logs.activity = "exit";

-- Other one said that the thief withdrew some money on Leggett Street in the morning.
SELECT people.name, atm_transactions.transaction_type
FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";


-- Last one said, he talked with someone less than a minute, planning earliest flight tomorrow.
-- Asked other one to purchase ticket
SELECT caller, caller_name, receiver, receiver_name FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

-- ALTER TABLE phone_calls
-- ADD caller_name text;

-- ALTER TABLE phone_calls
-- ADD receiver_name text;
-- ( made this one time to add columns)

UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;

-- Reciever Name on the phone calls must be the one that purchased the tickets
SELECT id, hour, minute, origin_airport_id, destination_airport_id
FROM flights
WHERE year = 2021 AND month = 7 AND day = 29
ORDER BY hour ASC
LIMIT 1;
-- ( We are not using it again because we are updating)

SELECT full_name, city
FROM airports
WHERE id IN (4, 8);
-- 8 is the origin and 4 is the destination

-- Who are going to the New York City, which is the destination
SELECT flights.destination_airport_id, name, phone_number, license_plate
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36
ORDER BY flights.hour ASC;

SELECT name
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN flights
ON flights.id = passengers.flight_id
WHERE (flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.id = 36)
AND name IN
(SELECT phone_calls.caller_name
FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60)
AND NAME IN
(SELECT people.name
FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw")
AND NAME IN
(SELECT people.name
FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.month = 7
AND bakery_security_logs.year = 2021
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25
AND bakery_security_logs.activity = "exit");

-- Intersection of the data that we have found 