# Write your MySQL query statement below
select firstName,lastName,city,state from Person
left join  Address
on person.personId=Address.personID;

