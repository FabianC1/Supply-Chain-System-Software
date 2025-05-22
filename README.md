# ⚠️ GROUP PROJECT NOTICE ⚠️

**This project is a group project originally developed and managed in [Azure DevOps](https://dev.azure.com/FG296/_git/Supply%20Chain%20System).**

https://dev.azure.com/FG296/_git/Supply%20Chain%20System

I was the **Project Manager** and **Lead Developer** on this project.

---

## How to run the software

First of all, the code needs to be compiled. In the CLI, run:

```bash
make clean
make
```

This will remove temporary .o files and compile all the files and classes.

After that, run the executable with the input file like this:
```
./supply_chain_system.exe games.txt
```

It is crucial that the .txt file is provided as a parameter to the executable, as the software uses it on startup.

When you run make, it also compiles system_tests.cpp into an executable file. To run the tests, type:
```
./system_tests.exe
```
This will compile and run all the Catch2 test cases.

---

### 3. Steps on How to Use the Software

## Steps on how to use the software

### 1. Purchase a product  
This option displays the current available games and allows the user to select a game to purchase.  
- If the game is out of stock, it will show a message like:  
  `"Sorry, Call of Duty: Modern Warfare is out of stock."`  
- If the item is in stock, it will ask the user to confirm the purchase (`y` or `n`), then prompt for their name.  
- After the purchase, it will display an automatically generated order ID.  
- The stock quantity will decrease by 1 in the UI (not updated in the `.txt` file, so the modification is volatile).

### 2. See orders & tracking status  
This option displays the order ID, product purchased, and status of the order.  
- The user is prompted to input the order ID they want to check.

### 3. See customers who have purchased  
Displays all users who have made a purchase using the software, showing their customer ID and name.  
Example:  
```
Enter your choice: 3
Customers who have purchased:
Customer ID: 1, Name: fab
Customer ID: 2, Name: nik
```


### 4. See stock  
Displays everything within the file — Game Name, Stock Quantity, and Price — formatted in a neat table, easily understood.  
Example:  

| Game Name                              | Stock Quantity | Price  |
|--------------------------------------|----------------|--------|
| Call of Duty: Modern Warfare         | 0              | £59.99 |
| FIFA 22                              | 18             | £49.99 |
| Assassin's Creed Valhalla            | 5              | £39.99 |
| The Legend of Zelda: Breath of the Wild | 20          | £59.99 |
| Cyberpunk 2077                      | 10             | £49.99 |
| Grand Theft Auto V                   | 3              | £29.99 |
| Red Dead Redemption 2                | 15             | £39.99 |
| Minecraft                          | 50             | £19.99 |
| The Witcher 3: Wild Hunt             | 20             | £29.99 |
| Overwatch                          | 35             | £39.99 |
| Super Mario Odyssey                  | 1              | £49.99 |
| Fortnite                           | 60             | £0.00  |
| PlayerUnknown's Battlegrounds (PUBG)| 2              | £29.99 |
| Madden NFL 22                      | 30             | £54.99 |
| Halo Infinite                     | 20             | £59.99 |
| Animal Crossing: New Horizons       | 15             | £49.99 |
| Final Fantasy VII Remake            | 5              | £44.99 |
| Among Us                          | 55             | £3.99  |
| Genshin Impact                    | 10             | £0.00  |
| Rainbow Six Siege                 | 20             | £19.99 |


### 5. Change order status  
This option allows the user to change the status of an order by incrementing it by 1 each time this option is selected.  
- The user is asked for the order ID to specify which order to update.  
- Multiple orders can be changed by repeating this process.

### 6. Cancel an existing order  
Displays existing orders and asks for the order ID to cancel an order, removing it completely from the system.

### 7. Exit  
Simply exits the program.

---

