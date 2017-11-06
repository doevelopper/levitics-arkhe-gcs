# language: en
Feature: Addition
	As a debugger 
	I want to log every 
	In order to avoid silly mistakes


	Scenario Outline: Logging services at all levels
		Given I have entered created a logging service
		And I have enabled all level
		When I run the application 
		Then All logging levels should be <output> on the screen/file

		Examples:
		| input_1 | input_2 | button | output |
		| 20      | 30      | add    | 50     |
		| 2       | 5       | add    | 7      |
		| 0       | 40      | add    | 40     |

