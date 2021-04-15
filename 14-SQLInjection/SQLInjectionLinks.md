# SQL Injection


SQL injection is one of the most common hacking techniques that places malicious code in SQL statements.


## Scenario 1


Consider the following code:
~~~
txtUserId = getRequestString("UserIdField");
txtSQL = "SELECT * FROM Users WHERE UserId = " + txtUserId;
~~~


Entering `JohnDoe` in the UserIDField yields the following safe SQL statement:
~~~
SELECT * FROM Users WHERE UserId = JohnDoe;
~~~


However, if `JohnDoe OR 1=1` is entered in the UserIdField, the resulting SQL statement will return **all** rows from the `Users` table:
~~~
SELECT * FROM Users WHERE UserId = JohnDoe or 1=1;
~~~


## Scenario 2

Consider the following code:
~~~
txtUserName = getRequestString("UserNameField");
txtPass = getRequestString("PasswordField");

txtSQL = 'SELECT * FROM Users WHERE Name ="' + txtUserName + '" AND Pass ="' + txtPass + '"'
~~~

Entreing `JohnDoe` and `myPass` in UserNameField and PasswordField results in the following safe and valid SQL statement:

~~~
SELECT * FROM Users WHERE Name ="JohnDoe" AND Pass ="myPass"
~~~

However, if a hacker enters `" or ""="` in the PasswordField, the resulting SQL query will return all rows from the `Users` table because `OR ""=""` is always true:

~~~
SELECT * FROM Users WHERE Name ="JohnDoe" AND Pass ="" or ""=""
~~~


## Scenario 3

Consider the following code:
~~~
txtUserId = getRequestString("UserIdField");
txtSQL = "SELECT * FROM Users WHERE UserId = " + txtUserId;
~~~

An attacker might attempt to use a batched SQL statement to corrupt or modify the database by entering `JohnDoe; DROP TABLE Suppliers` into UserIdField. This qoudl result in teh following SQL statement:
~~~
SELECT * FROM Users WHERE UserId = JohnDoe; DROP TABLE Suppliers;
~~~


## Live examples

[Live demo](https://www.codingame.com/playgrounds/154/sql-injection-demo/sql-injection)  of SQL injection with code

Traces of SQL injection in action: try searching for "hammer" or "hammers" at [www.harryepstein.com](https://www.harryepstein.com)