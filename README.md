# CCPROG1
Logic Formulation and Introductory Programming

Restaurants and fast-food chains have been using ordering systems for handling orders. These kinds of
systems not only takes inputs of the orders but also computes the amount due for the order. This project
will have you develop such a system.

The following tables will show the food items available and their prices.
Mains:
ID Type Price
1 Chicken 90.00
2 Pork 105.00
3 Fish 120.00
4 Beef 135.00
Table 1: List of main dishes and their corresponding prices
Sides:
ID Type Price
1 Steamed Rice 20.00
2 Shredded Corn 35.00
3 Mashed Potatoes 50.00
4 Steam Vegetables 65.00
Table 2: List of side dishes and their corresponding prices
Drinks:
ID Type Price
1 Mineral Water 25.00
2 Iced Tea 35.00
3 Soda 45.00
4 Fruit Juice 55.00
Table 3: List of drink and their corresponding prices
Order – An order is the process where the user will input 1 main, 1 side and 1 drink.
Meal Set of the day – A meal set that is randomly selected by the system for the day. Customers who
order the set of the day will have a discount of 15% off for that specific set. This set will change daily.
Features:
Ordering:
A customer can make three(3) orders or less. They are allowed to only order specific items from
either the main, sides or drinks(eg. Only order a main and nothing else).
Example:
Order 1:
Main: 3
Fish
Side: 0
None
Drink: 0
None
Order 2:
Main: 0
None
Side: 3
Mashed Potatoes
Drink: 4
Fruit Juice
Order 3:
Main: 1
Chicken
Side: 1
Steamed Rice
Drink: 0
None
Each type is limited to 1 piece. (eg. 2 mains in 1 order is not allowed).
Cancelling:
The system will allow the user to cancel an order.
● The system will have the option to let the user cancel an order at the start of the
next order. The system will then proceed to the Amount Due part.
Example: The customer initially decided to make 2 orders but then decides that
he/she only wants to make order 1 instead. After selecting the items
for the first order(main, side and drink), the user may select the cancel
option for the second order.
● The system will have also have the option to let the user cancel an order after all
orders have finished OR before the start of the first order. The system will then
go back to the Ordering part.
Modifying/Changing Order of a Meal Set:
The system will allow a specific order to be modified. This will happen only after finishing
inputting each item for that order. Specifically, after the input for the drink. The system will
prompt the user to confirm if the order is correct. If the user selects no, then the system will
repeat the process for that order.
Example:
Order 1:
Main: 1
Pork
Side: 2
Shredded Corn
Drink: 3
Soda
Is this meal set order correct(Y/N)? N
Order 1:
Main: 3
Pork
Side: 4
Steamed Vegetables
Drink: 1
Mineral Water
Is this meal set order correct(Y/N)? Y
Order 2:
Main: ...
Total Amount Due:
The system will be able to display the subtotals and total amount that the customer must pay for
their order. If a customer orders the Meal Set of the day, the discount will be listed under that
set.
Example:
Order 1:
Main: Fish P120.00
Side: Shredded Corn P35.00
Drink: Soda P45.00
Meal Set of the day Discount 15%
Subtotal: P170.00
Order 2:
Main: Pork P105.00
Side: Mashed Potatos P50.00
Drink: None P0.00
Subtotal: P155.00
Total Amount Due: P325.00
