# Green Guardian Initiative

## Project Overview

Imagine a piece of land once vibrant and full of life, now silenced by the shadow of pollution. This land, tainted by hazardous waste, cries out for a hero to restore its lost glory. Your mission, should you choose to accept it (and you should, because it's 20% of your grade), is to become that hero. Using the principles of Object-Oriented Programming (OOP), you will simulate the healing process of this land, turning a desolate grid into a thriving ecosystem once more.

### Setting the Scene

In this simulation, you are the mastermind behind "The Green Guardians" project. You'll be working with a digital plot of land, represented as a square grid on your screen. Each square, or "cell," in this grid is a piece of the land with its own story, its own level of toxicity that has been randomly determined by the twists of fate (or in this case, by our program at the start).

Your tools for this mission are seeds - not ordinary ones, but special, resilient seeds capable of growing in even the most hostile environments. Your program will randomly plant seeds of varying amounts in each cell in the interests of pure experimentation.  You will watch as your seeds grow, spread, and hopefully breathe life back into the soil.

But beware, for challenges await. The land is not as deserted as it seems. Small predators, such as cunning gophers or stealthy rats, roam the grid, ready to devour your precious seeds and hinder your progress. And yet, nature has its own guardians. Wolves, the apex predators, roam the grid, keeping the smaller predators in check, adding a layer of balance to this intricate dance of life.

## Simulation Criteria and Requirements

##### Make sure to read the Project Constants section for details like grid size and upper and lower bounds for random values.

### The Simulation Environment

- **The Grid:** Your simulation will take place on a grid composed of unit cells. Each cell has an initial random toxicity level that you'll need to manage and reduce through bio-remediation.

### Initial Setup

- **Game Modes**: The game will either be initialized randomly or from a file. The factors you need to keep in mind include:
	- Toxicity level for each cell.
	- \# and Placement of Seeds
	- \# and Placement of Predators
- **Seeds Placement:** At the beginning (year 0), distribute a random number of seeds across various cells in the grid. These seeds are the foundation of your bio-remediation efforts.

### The Life Cycle of Plants

- **Growth:** Seeds grow into mature plants after surviving for one year.
- **Reproduction:** Mature plants will produce one new seed in their second year and two seeds in their third year.
	- Seeds can wind up in the current cell, or any adjacent one.
- **Death:** Plants die after their third year, and the cycle continues with the new seeds they've produced.
- **Toxicity Reduction:** For every group of 5 mature plants in a cell, the toxicity level of that cell is reduced by 1 each year. Don't use decimals for the toxicity level and don't round up.
- **Cell Occupancy:** There's no limit to the number of plants in a cell.
### Predator Dynamics

**Gophers** and **Rats** challenge your remediation efforts by eating seeds.
- **Rats** move up to 4 cells in any direction and can eat 1 seed. If a rat doesn't eat for 2 consecutive years, it dies.
- **Gophers** move up to 2 cells in any direction and can eat 2 seeds. Gophers die if they don't eat for 3 consecutive years.
**Wolves** help control the population of rats and gophers.
- **Wolves** move up to 5 cells in any direction. They can eat either a rat or a gopher (not both) in a cell. Wolves die if they don't eat for 3 consecutive years.

**Cell Occupancy:** A cell can host up to 3 rats, 1 gopher, and 1 wolf simultaneously.
**Movement notes**: 
- The direction a predator moves is randomized with each square it moves.
- The predator will stop moving when it finds something to eat.
- A predator must move at least one cell per year.
**Tracking Movement**: keep a record of the cells that each predator visits in each year of the simulation beginning in year 1. Notate visited cells in the form of a tuple indicating row/column numbers; for example, (x,y). You should save these tuples in a data structure as specified in Project Constants.

### Simulation Progression

- **Annual Update:** Each year, update the state of the grid. This includes factors like plant growth, seed reproduction, predator movements, feeding actions, and changes in cell toxicity.
### Conclusion and Analysis

- At the end of the 7-year simulation period, assess the impact of your bio-remediation efforts.
    - **Toxicity Levels:** Calculate the final toxicity levels of each cell, considering the cumulative effect of mature plants.
    - **Statistical Summary:** Provide statistics on the number of seeds produced, eaten, and the final state of each cell's toxicity.
- You must print these simulation results to an output file.

### Additional Features

- **Visualization:** Consider ways to visually represent the grid, cells, plants, and predators to make the simulation more engaging and informative.
- **Interactive Menu:** Include a menu for users to view statistics, rerun the simulation, or exit the program.
	- All outputs should be nicely formatted into rows and columns anywhere appropriate.
	- The menu choices should be at least:
		1. Run Simulation
			- Randomized Initialization
			- Initialize from file
		1. View number of seeds produced, eaten, and died      
		2. View cells visited by gophers      
		3. View final toxicity level of each cell   
		4. Re-run simulation
		5. Quit


## Project Constants

| Constant Description          | Value / Range |
| ----------------------------- | ------------- |
| **Grid Size**                 | 5x5           |
| **Simulation Duration**       | 7 years       |
| **Cell Toxicity Level Range** | [3,7]         |
| **Initial Seed Distribution** | [10,15]       |
| **Predator Feeding years**    | [1,7]         |
| **Initial Rat Range**         | [5,9]         |
| **Initial Gopher Range**      | [3,7]         |
| **Initial Wolf Range**        | [2,5]         |

## Grading Criteria

Your project will be evaluated based on how well you've implemented the following Object-Oriented Programming concepts and programming best practices:

1. **Object-Oriented Design:**
    - Your program must be designed around the principles of Object-Oriented Programming. Classes should be used to represent different entities where appropriate.
2. **Use of Dynamic Memory:**
    - Proper use of dynamic memory allocation (using `new` and `delete`) is expected, especially for managing collections of objects.
3. **Class Structures:**
    - Demonstrate understanding of class structures, including attributes, methods, and access specifiers (public, protected, private).
4. **Inheritance and Polymorphism:**
    - Your design should include examples of inheritance, showcasing the relationship between base and derived classes. Polymorphism should be used to allow for dynamic method binding.
5. **Encapsulation and Abstraction:**
    - Encapsulation should be evident through the use of classes to hide implementation details. Abstraction should be used to provide interfaces for classes, making the implementation details irrelevant to the user.
6. **Proper Use of Containers:**
    - Use C++ Standard Library containers (e.g., vectors, lists) to manage collections of objects efficiently.
7. **File Organization:**
    - Code should be well-organized across multiple files, typically separating class declarations in header files (.h) and definitions in implementation files (.cpp).
8. **Macro Guards in Header Files:**
    - Header files should contain macro guards to prevent multiple inclusions.
9. **Code Formatting:**
    - Your code should be well-formatted, using consistent indentation and whitespace to enhance readability.
10. **Efficient Memory Use:**
    - Demonstrate efficient memory use, avoiding memory leaks by properly deallocating dynamically allocated memory.
11. **Use of `const` and Pass-by-Reference:**
    - Where appropriate, use `const` to prevent modification of parameters passed to functions. Utilize pass-by-reference to avoid unnecessary copying of complex objects.
12. **Function Overloading and Default Arguments:**
    - Use function overloading to create functions with the same name but different parameters. Default arguments can be used to provide default values for function parameters.
13. **Error Handling:**
    - Implement error handling to manage unexpected situations or input errors gracefully.
14. **Documentation:**
    - Your code should be well-documented, including comments explaining the purpose of classes and methods, and any complex logic.

## Submission Instructions

To ensure a smooth submission and review process, please adhere to the following guidelines:

1. **Project Submission:**
    - Commit and push your complete project to your assigned GitHub Classroom repository.
2. **File Initialization**: You must include at least 3 files that can be used to load an initial game state from files. The formatting of those files is up to you. You must include a guide to their layout in your README.md documentation.
3. **Documentation:**
    - Alongside your code, include a README.md within your repository. Repository READMEs are written in Markdown, the standard document writing language for code repositories that controls formatting mostly through typing, rather than a toolbar. Here is a page that gives an overview of the formatting commands: [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)
    - This README.md should be at the top level of your repo and include at least the following sections.
        - **Compilation Instructions:** Detailed steps on how to compile your project, including any required flags or commands.
        - **Execution Instructions:** Clear instructions on how to run your project, specifying any required arguments or inputs.
        - **Project Status:** An overview of the current state of your project, highlighting whether it is complete, any known bugs, or incomplete features.
        - **Manual**: Include a brief, yet informative instruction manual telling users how to interact with your program and what it does. Include a brief description of your code design and how you went about implementing the project. Assume the reader is not familiar with the project before reading your manual.
        - **UML Diagrams**: Include UML diagrams for all of your classes. We recommend using [Mermaid](https://mermaid.live) , a convenient tool for building charts using a code-like syntax. You can embed the Mermaid code directly into your .md file using a markdown code block (open with \`\`\`mermaid and end the block with \`\`\`) and the code will render into the diagram. Think of the backticks like curly braces bundling the UML code together.
	        - [Mermaid Cheat Sheet](https://mermaid.js.org/syntax/classDiagram.html)
		    You may use whatever tool you like to make the UML Diagrams (like another online tool, or any tool that lets you make tables, like Excel \[Free for you with your student email])
		    Include the UMLs either embedded into your `README.md `or in their own `UML.pdf` file. Your choice.
 4. **Compatibility:**
    - Your project must be fully functional within GitHub Codespaces. This is crucial for ensuring that your project can be run and evaluated in a standardized environment.
    - You can still develop locally, but you should still ensure your code behaves as expected within a Codespace before committing.
