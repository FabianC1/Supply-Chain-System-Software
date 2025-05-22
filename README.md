# ⚠️ GROUP PROJECT NOTICE ⚠️

**This project is a group project originally developed and managed in [Azure DevOps](https://dev.azure.com/FG296/_git/Supply%20Chain%20System).**

I was the **Project Manager (Leader)** and **Lead Developer** on this project.

---



How to run the software:

First of all, the code needs to be complied. So in the CLI, run the "make clean" to remove the temporary .o files, and then input "make". It will compile all of the files and classes.
After that, simply type this " ./supply_chain_system.exe games.txt". 

It is crucial that you write the txt file with the exe, as the software uses it as a parameter when it starts up.

When 'make' is run it also compiles the system_tests.cpp into an executable file, in order to run this simply type './system_tests.exe'. This will compile and run all the catch2 test cases.


Steps on how to use the software:
1. Purchase a product || This option displays the current available games, and allows the user to select a game they want to purchase. If the game is out stock, itll tell the 
user something like this: "Sorry, Call of Duty: Modern Warfare is out of stock." If the item is in stock, itll ask the user if they are sure they want to purchase the item. 
When they say yes (y) or no (n), itll ask the user to input their name. Once they have input their name, itll tell them the order ID, which is automatically generated. Once 
the user has purchased a product, the stock will go down by 1. (Not in the txt file, just in the UI, so any modification is volatile)

2. See orders & tracking status || This option dispays the order ID, product purchased, and the status of the order. 
But before this, it asks the user to input the order ID they want to check. 

3. See customers who have purchased || This option displays all of the users who have made a purchase using the software. 
Their customer ID and their name will also be displayed. For example:
-------------------------------------
Enter your choice: 3
Customers who have purchased:
Customer ID: 1, Name: fab
Customer ID: 2, Name: nik
-------------------------------------

4. See stock || This option simply displays everything within the file, including Game name, Stock Quantity, and Price. It displays it in a foramtted and neat table, easily understood. 
Like this:
Enter your choice: 4
Stock:
|-----------------------------------------------------------------------------------------|
|                Game Name                   | Stock Quantity |            Price          |
|-----------------------------------------------------------------------------------------|
| Call of Duty: Modern Warfare               | 0              | £59.99                    |
| FIFA 22                                    | 18             | £49.99                    |
| Assassin's Creed Valhalla                  | 5              | £39.99                    |
| The Legend of Zelda: Breath of the Wild    | 20             | £59.99                    |
| Cyberpunk 2077                             | 10             | £49.99                    |
| Grand Theft Auto V                         | 3              | £29.99                    |
| Red Dead Redemption 2                      | 15             | £39.99                    |
| Minecraft                                  | 50             | £19.99                    |
| The Witcher 3: Wild Hunt                   | 20             | £29.99                    |
| Overwatch                                  | 35             | £39.99                    |
| Super Mario Odyssey                        | 1              | £49.99                    |
| Fortnite                                   | 60             | £0.00                     |
| PlayerUnknown's Battlegrounds (PUBG)       | 2              | £29.99                    |
| Madden NFL 22                              | 30             | £54.99                    |
| Halo Infinite                              | 20             | £59.99                    |
| Animal Crossing: New Horizons              | 15             | £49.99                    |
| Final Fantasy VII Remake                   | 5              | £44.99                    |
| Among Us                                   | 55             | £3.99                     |
| Genshin Impact                             | 10             | £0.00                     |
| Rainbow Six Siege                          | 20             | £19.99                    |
|-----------------------------------------------------------------------------------------|

5. Change order status || This choice allows the user to change the status of the order. This does it by automatically incrementing the status by 1, each time the 5th option is selected.
Before changing the status, it asks for the order ID, so that the order is specified, and then changed. This allows multiple order to be changed.

6. Cancel an existing order || This option displays the existing orders, and asks for the order ID, so that they can cancel wichever order they wish. So it removes it from the system
completely.

7. Exit || This simply exits the program.
