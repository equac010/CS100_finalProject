[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9890085&assignment_repo_type=AssignmentRepo)
# Calorie Tracker App
 
#### Authors: [Ethan Quach](https://github.com/equac010), [Daniel Sadeghi](https://github.com/daniel-sadeghi), [Edward Song](https://github.com/edsng), [Vincent Tang](https://github.com/vtang020), [Daniel Lin](https://github.com/DaDanielL)

## Project Description

As more and more people start to get into fitness, the necessity for free calorie tracking apps increases. More importantly, while many people are wary about their dietary health, the time it takes to track your calories and nutrition deters many from consistently recording their intake and maintaining a healthy diet. We aim for our app to streamline the meal planning and calorie tracking process to encourage our users to upkeep their dietary health without taking too much of their daily time and effort. We plan to do so through features such as a record of all the user's previously logged food. 

We aim to create a desktop GUI with Qt Creator (approval pending) with C++ for front and backend. Therefore, our application will have an user-friendly interface for our users to interact with it easily and efficiently.

Obviously, our application need input from the user of the food they ate and its nutritional fact (input) in order to show the user their current daily caloric and nutritional intake (output). The app will also be able to take in the users' physical conditions (weight, height) and other information (activity level, desire to bulk or cut) to provide them with the suggested caloric intake amount.

Addition features our application will provide is calendar view of the user's dietary history, weekly reports, assistance with nutrition goal keeping, saved food and meal list, tracking for other nutrients like protein, carbohydrate, and fat.

## Class Diagram
MVC Pattern
![MVC Class Diagram](https://i.imgur.com/ZdKb0B5.png)
![Internal Class Diagram](https://i.imgur.com/PLvmmwP.png)
![UI Flow Diagram](https://i.imgur.com/F1BUcdA.png)

This application will employ a Model-View-Controller architecture. User interactions will be sent to the MWController class that will notify the Model (our data and back end logic) in order to receive the proper data, and then pass that data to the MainWindow class so that it can display the information properly. The Model class is composed of Database objects, which would be used to store information about what the user has eaten and will be implemented with Food objects as shown in the internal class diagram.

Our backend will employ the DailyInfo class to keep track of the user's current daily macros and meals. DailyInfo will have an aggregation of Meal objects, which are an aggregation of Food objects. Nutrition and FoodNutrition classes will serve to group of the macros values like carbohydrates, proteins, and fats. Finally the FoodSaver class will help save Food object so the user can save their food for future logging. The DailyInfoOutputter will help output information that reflects the user's current daily macros using the DailyInfo class.

## Backend Class Diagram (Updated for SOLIDS)
![Internal Class Diagram](https://i.imgur.com/TisbxnA.png)

(refer to older versions for better description)

Change #1: A DailyInfoEditor class is added to the DailyInfo class in consideration of the single responsibility principle. The DailyInfoEditor will take care of removing and adding Food objects into the DailyInfo class. In doing so, we are cutting down the size of the DailyInfo class and making the code more manageable. This change would also reduce the likelihood of merge conflicts in the future as changes to the implementations of how we edit allMeals now does not affect the DailyInfo class.

Change #2: In consideration of the dependency inversion principle, Food, Meal, and DailyInfo now inherits from a new ICanCalcTotalNutrition interface. These classes now must implement the calcTotalNutrition() method in their own ways. This change will allow future, higher-level classes depending on the abstraction of the aforementioned method instead of low-level implementations, thus making future potential changes to the low-level implementations less costly.

Change #3: In application of the dependency inversion principle, instead of implementing 3 different, separate classes responsible for saving and fetching user data, we know have FoodDataManager, MealDataManger, and DailyInfoDataManager all inheriting from an abstract DataManager class. This way, future changes to the 3 low-level, child classes will be less costly as the high-level classes that call them would not be affected by the changes.

Change #4: In consideration of the open-closed principle, an MealItem interface is added, and the Food class inherits from it. Name is the only attribute of the interface. This change will make future additions of classes, such as Beverage, to be less costly because no changes would have to be made to the Meal class and other potential classes that could currently depend on the Food class.

## FINAL DELIVERABLES
 
 ## Screenshots
 ![GUI 1](https://i.imgur.com/Y4eLvYm.png)
 ![GUI 2](https://i.imgur.com/fS7VMbi.png)
 ![Terminal Executable 1](https://i.imgur.com/6ma29oI.png)
 ![Terminal Executable 2](https://i.imgur.com/s0ib7az.png)
 ## Installation/Usage
 QT GUI Application:
 
 1. install [QT Creator](https://www.qt.io/download)
 2. open QT Creator
 3. select create project
 4. select import project -> git clone -> Choose
 5. enter the repository link into the "Repository" field (https://github.com/cs100/final-project-surfin-and-mergin.git)
 6. type in master in the "Branch" field
 7. check recursive and click continue
 8. run program/application by clicking the button at the bottom left

 Terminal GUI Application:
 
 1. Open terminal and cd into desired directory
 2. clone this repository by typing in ```git clone https://github.com/cs100/final-project-surfin-and-mergin.git```
 3. cd into that cloned, local repository
 4. type ```cmake .```
 5. type in ```make``` to compile executable
 6. type in ```./bin/main``` to run program executable
 ## Testing
Testing was split into two parts, frontend and backend. For the backend, the Google Test framework was used and a test suite was written for each backend class. Every method is tested extensively and every method in the backend classes (excluding some setters and getters) is covered by at least one test case. Moreover, Valgrind/Memcheck was ran on both the backend terminal executable and test executable, ultimately, it was determined that both executable reaches Memcheck clean with no memory loss.

As for the frontend, a checklist for frontend elements is created as to validate the frontend for the GUI application built with QT creator is functioning properly:

- [x] User's target nutrition for the day should be shown clearly on the application window.
- [x] User's current nutrition for the day should be shown clearly and updating everytime new food is logged.
- [x] There is a button for the user to choose to add/remove food items.
- [x] User should be given a clear indication as to whether their daily nutrition goal have been reached.
- [x] For every food item logged, all the nutrition values (Calories, Carbohydrates, Protein, Fat) should be clearly listed.
- [x] User should be able to easily see the name of the foods they entered.
- [x] User should be able to log their food and enter relevant information through a form field.
- [x] All buttons, fields, textboxes are labeled correctly.
- [x] All frontend elements should be organized and spaced out correctly.
- [x] There should be a visualization of the user's current progress with regards to their daily nutrition goal.
 
