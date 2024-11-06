-- Keep a log of any SQL queries you execute as you solve the mystery.
-- crime scene reports 27-07-2021 humphrey street
select description from crime_scene_reports where year = 2021 and month = 7 and day = 28 and street = 'Humphrey Street';
--check interview transcripts mentioning bakery
select name, transcript from interviews where year = 2021 and month = 7 and day = 28;
--ruth, eugene and raymond witnessed the thief. possible accomplice according to raymond's testimony.
--ruth angle : check parking sequrity footage
select name, bakery_security_logs.hour, bakery_security_logs.minute from people join bakery_security_logs on people.license_plate = bakery_security_logs.license_plate where bakery_security_logs.year = 2021 and bakery_security_logs.month = 7 and bakery_security_logs.day = 28 and bakery_security_logs.activity = 'exit' and bakery_security_logs.hour = 10 and bakery_security_logs.minute >=15 and bakery_security_logs.minute <= 25 order by bakery_security_logs.minute;
--possible suspects : venessa, bruce, barry, luca, sofia, iman, diana and kelsey
--eugene angle : check atm logs at leggett street
select name, atm_transactions.amount from people join bank_accounts on people.id = bank_accounts.person_id join atm_transactions on bank_accounts.account_number = atm_transactions.account_number where atm_transactions.year = 2021 and atm_transactions.month = 7 and atm_transactions.day = 28 and atm_transactions.atm_location = 'Leggett Street' and atm_transactions.transaction_type = 'withdraw';
--narrowing down suspect list. current possible suspects are as follows : bruce, diana, iman and luca
-- raymond angle : check call logs and check flights out of fiftyville at 29-07-2021
--caller logs
select name, phone_calls.duration from people join phone_calls on people.phone_number = phone_calls.caller where phone_calls.year = 2021 and phone_calls.month = 7 and phone_calls.day = 28 and phone_calls.duration <= 60 order by phone_calls.duration;
--narrowing down suspect list further. current possible suspects are as follows : bruce and diana
--reciever logs
select name, phone_calls.duration from people join phone_calls on people.phone_number = phone_calls.receiver where phone_calls.year = 2021 and phone_calls.month = 7 and phone_calls.day = 28 and phone_calls.duration <= 60 order by phone_calls.duration;
--possible accomplices : larry, jacqueline, james, robin, phillip, melissa, jack, anna and doris
--flights on 29 jul
select flights.id, full_name, city, flights.hour, flights.minute from airports join flights on airports.id = flights.destination_airport_id where flights.origin_airport_id = (select id from airports where city = 'Fiftyville') and flights.year = 2021 and flights.month = 7 and flights.day = 29 order by flights.hour, flights.minute;
--5 flights. check passengers
select passengers.flight_id, name, passengers.passport_number, passengers.seat from people join passengers on people.passport_number = passengers.passport_number join flights on passengers.flight_id = flights.id where flights.year = 2021 and flights.month = 7 and flights.day = 29 and flights.hour = 8 and flights.minute = 20 order by passengers.passport_number;
-- bruce is the thief
-- refering back to the call logs accomplice is most likely robin

