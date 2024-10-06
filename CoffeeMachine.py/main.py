from tabulate import tabulate

class CoffeeMachine:
    drinks = {
        "espresso": {
            "water": 250,
            "milk": 0,
            "coffee": 16,
            "cost": 4
        },
        "latte": {
            "water": 350,
            "milk": 75,
            "coffee": 20,
            "cost": 7
        },
        "cappuccino": {
            "water": 200,
            "milk": 100,
            "coffee": 12,
            "cost": 6
        }
    }

    def __init__(self):
        self.water = 0
        self.sugar = 0
        self.milk = 0
        self.coffee = 0
        self.cups = 0
        self.money = 0

    def display_drinks(self):
        print("The available drinks are: ")
        print(tabulate(self.drinks.items(), headers=["Drink", "Details"], tablefmt="pretty"))

    def add_resource(self):
        resource_input = input("What resource would you like to add? (water/milk/coffee/cups): ")
        if resource_input == "water":
            self.water += int(input("How much water would you like to add? "))
        elif resource_input == "milk": 
            self.milk += int(input("How much milk would you like to add? "))
        elif resource_input == "coffee":
            self.coffee += int(input("How much coffee would you like to add? "))
        elif resource_input == "cups":
            self.cups += int(input("How many cups would you like to add? "))
        else:
            print("Invalid resource.")

    def remove_resource(self):
        resource_input = input("What resource would you like to remove? (water/milk/coffee/cups): ")
        if resource_input == "water":
            self.water -= int(input("How much water would you like to remove? "))
        elif resource_input == "milk": 
            self.milk -= int(input("How much milk would you like to remove? "))
        elif resource_input == "coffee":
            self.coffee -= int(input("How much coffee would you like to remove? "))
        elif resource_input == "cups":
            self.cups -= int(input("How many cups would you like to remove? "))
        else:
            print("Invalid resource.")

    def add_drink(self):
        drink_name = input("What drink would you like to add? (new drink name): ").lower()
        if drink_name in self.drinks:
            print("Drink already exists.")
        else:
            self.drinks[drink_name] = {
                "water": int(input("How much water does the drink require? ")),
                "milk": int(input("How much milk does the drink require? ")),
                "coffee": int(input("How much coffee does the drink require? ")),
                "cost": int(input("How much does the drink cost? "))
            }

    def remove_drink(self):
        drink_name = input("What drink would you like to remove? (espresso/latte/cappuccino): ").lower()
        if drink_name in self.drinks:
            del self.drinks[drink_name]
        else:
            print("Drink does not exist.")
    
    def take_money(self):
        withdraw = int(input("How much money would you like to withdraw? "))
        if withdraw > self.money:
            print("Not enough money in the machine.")
        else:
            self.money -= withdraw
            print(f"Remaining money: {self.money}")

    def check_resources(self, drink):
        for resource, amount in drink.items():
            if resource == "water" and self.water < amount:
                print("Sorry, not enough water.")
                return False
            if resource == "milk" and self.milk < amount:
                print("Sorry, not enough milk.")
                return False
            if resource == "coffee" and self.coffee < amount:
                print("Sorry, not enough coffee.")
                return False
        if self.cups == 0:
            print("Sorry, not enough cups.")
            return False
        return True
    
    def choose_drink(self):
        drink_name = input("What would you like? (espresso/latte/cappuccino): ").lower()
        if drink_name in self.drinks:
            if self.check_resources(self.drinks[drink_name]):
                return drink_name
        else:
            print("Invalid choice.")
            return self.choose_drink()

    def insert_coins(self):
        return int(input("Please insert coins: "))

    def process_coins(self, selected_drink):
        drink_cost = self.drinks[selected_drink]["cost"]
        inserted_money = self.insert_coins()

        if inserted_money >= drink_cost:
            self.money += drink_cost
            change = inserted_money - drink_cost
            if change > 0:
                print(f"Please take your change: {change}")
            return True
        else:
            print("Not enough money. Transaction canceled.")
            return False
    
    def make_drink(self, drink_name):
        for resource, amount in self.drinks[drink_name].items():
            if resource == "water":
                self.water -= amount
            elif resource == "milk":
                self.milk -= amount
            elif resource == "coffee":
                self.coffee -= amount
        self.cups -= 1
        print(f"Here is your {drink_name}!")

    def run(self):
        self.display_drinks()
        while True:
            selected_drink = self.choose_drink()
            if self.process_coins(selected_drink):
                self.make_drink(selected_drink)
            self.display_drinks()

class Person:
    def __init__(self, name, coffee_machine):
        self.name = name
        self.drink = coffee_machine.choose_drink()
        self.coins = coffee_machine.insert_coins()

    def display(self):
        print(f"Name: {self.name}")
        print(f"Drink: {self.drink}")

    def get_drink(self):
        return self.drink

class Admin:
    def __init__(self, name, password):
        self.name = name
        self.password = password

    def display(self):
        print(f"Admin Name: {self.name}")
        print(f"Password: {self.password}")

    def change_password(self, new_password):
        self.password = new_password

    CoffeeMachine.s

machine = CoffeeMachine()
machine.run()