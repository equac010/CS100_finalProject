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

This application will employ a Model-View-Controller architecture. User interactions will be sent to the MWController class that will notify the Model (our data and back end logic) in order to receive the proper data, and then pass that data to the MainWindow class so that it can display the information properly. The Model class is composed of Database objects, which would be used to store information about what the user has eaten and will be implemented with Food objects as shown in the internal class diagram.

Our backend will employ the DailyInfo class to keep track of the user's current daily macros and meals. DailyInfo will have an aggregation of Meal objects, which are an aggregation of Food objects. Nutrition and FoodNutrition classes will serve to group of the macros values like carbohydrates, proteins, and fats. Finally the FoodSaver class will help save Food object so the user can save their food for future logging. The DailyInfoOutputter will help output information that reflects the user's current daily macros using the DailyInfo class.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.
## Backend Class Diagram (Updated)
![Internal Class Diagram](https://i.imgur.com/EenCpQW.png)
Change #1: A DailyInfoEditor class is added to the DailyInfo class in consideration of the single responsibility principle. The DailyInfoEditor will take care of removing and adding Food objects into the DailyInfo class. In doing so, we are cutting down the size of the DailyInfo class and making the code more manageable. This change would also reduce the likelihood of merge conflicts in the future as changes to the implementations of how we edit allMeals now does not affect the DailyInfo class.
Change #2: In consideration of the dependency inversion principle, Food, Meal, and DailyInfo now inherits from a new ICanCalcTotalNutrition interface. These classes now must implement the calcTotalNutrition() method in their own ways. This change will allow future, higher-level classes depending on the abstraction of the aforementioned method instead of low-level implementations, thus making future potential changes to the low-level implementations less costly.
Change #3: In application of the dependency inversion principle, instead of implementing 3 different, separate classes responsible for saving and fetching user data, we know have FoodDataManager, MealDataManger, and DailyInfoDataManager all inheriting from an abstract DataManager class. This way, future changes to the 3 low-level, child classes will be less costly as the high-level classes that call them would not be affected by the changes.
Change #4: In consideration of the open-closed principle, an MealItem interface is added, and the Food class inherits from it. Name is the only attribute of the interface. This change will make future additions of classes, such as Beverage, to be less costly because no changes would have to be made to the Meal class and other potential classes that could currently depend on the Food class.
 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
