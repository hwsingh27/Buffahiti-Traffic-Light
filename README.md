# PES-Assignment-4
@file: Buffahiti_Assignment_4<br/>
@author: Harshwardhan Singh<br/>
@date: October 12th 2021<br/>

##statemachine.c file<br/>
This statemachine.c file consists of nine states: STOP, STOP_GO_TRANSITION, GO, GO_WARNING_TRANSITION, WARNING, WARNING_STOP_TRANSITION, CROSSWALK_TRANSITION,
CROSSWALK and CROSSWALK_GO_TRANSITION. In each the starting and ending color changes as required. If Touch Slider reads any value or Switch is pressed, 
the transition occurs from the current state to the CROSSWALK_TRANSITION state and then to the CROSSWALK state. In CROSSWALK state, the LED toggles for 10msec
in a sequence of 750msec ON and 250msec OFF. 

##Appoach<br/>
SysTick Timer is used to keep the track of time. PWM is used to operate the LED using duty cycles. Interrupt has been used to accomplish the functionality
of Switch being pressed at any state. Diagonostic output is printed in the terminal of MCUXrpesso IDE after selecting Serial Terminal and COM6 port.
For displaying the time since startup, Now() is multiplied by 10 i.e. Now() x 10 because it count counts to 10msec. Hence, Now() multiplied by 10 to give the
correct timing. While creating the New Project, UART ws chosen instead of Semihost. The color computation during transitioning was done using the mathematical
equation.<br/>

log.h file is for conditional compiling where, if the program is in Debug mode, then the printf() statements i.e. LOG() will be executed whereas if the program is
working on Release mode then the printf() statements should not be printed on the console window.<br/>
Two build targets were configured using the following steps:<br/>
Go to Projects -> Properties -> C/C++ Build -> Settings -> MCU Compiler -> Preprocessor<br/>
Now select Release from the Configuration drop-down window -> select DEBUG and remove the file -> click on Apply and Close<br/>
Target can be changed by selecting the Debug and RUN mode accordingly from the Debug option (Hammer symbol on the top).<br/>
common.h file is created to simplify the program and made it look neat as the header (hash include) files are used almost in every .c files. 
Hence, it was made common so that it could be implemented anywhere.<br/>

##Extra Credit<br/>
GPIO Pin-7 of Port-D interrupt is used to check if there comes any interrupt. After the interrupt, the state changes from the current state to the CROSSWALK_TRANSITION
state, works same as Capacitive Slider. But, while transitioning to CROSSWALK state and in the CROSSWALK state, the capacitive slider and button pressed is not detected
as per the requirements. As soon as the CROSSWALK state is done, the CROSSWALK_STOP_TRANSITION begins and goes to the STOP state.
