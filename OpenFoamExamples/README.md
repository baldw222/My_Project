# Software Abstract:
OpenFoam is free open source C++ based software used for Computational Fluid Dynamics (CFD), it is utilized all throughout the STEM field to find flaws in designs and visulize certain properties we cannot see with the naked eye. It has been widely used by car manfufacturers and other companies to model cars and other modes of transportation to visualize the aerodynamics of the vehicle, and to improve upon it. 


# Installation/ Compilation
1. clone the repo for both the OpenFoam software and the third party example scripts using commands:
    - git clone https://github.com/OpenFOAM/OpenFOAM-8.git
    - git clone https://github.com/OpenFOAM/ThirdParty-8.git 
    - I have also added a install script titled "install.sb" in this directory, this command should create two new directories.

2. Navigate into the OpenFOAM-8 directory and source and set the enviornment variables using:
    - source (Your home directory)/OpenFOAM-8/etc/bashrc (If using bash)
    - source (Your home directory)/OpenFOAM-8/etc/cshrc  (If using tcsh)

3. After setting the enviornment compile the software using use the command:
    - ./Allwmake to compile in serial (Takes several hours, not recomended)
    - ./Allwmake -j to compile in parallel with all available cores and hyperthreads

# Example Code
I found examples for Formula 1 aerodynamics but they were for a different CFD software called Ansys, I tried to get the code to work for OpenFOAM but it was challenging converting to ascii and I ran out of time. Luckily these repos have examples you can run.

After compiling the software you should be able to run the example by executing the "flame.sb" file using the bash flame.sb command. This file is essentialy grabbing a directory deep inside the OpenFOAM-8 repo and copying it over. It then will navigate into the directories needed for the example and run it. 

# References
-Github page for OpenFoam version 8: https://github.com/OpenFOAM/OpenFOAM-8

-Github page for the Third Party example scripts: https://github.com/OpenFOAM/ThirdParty-8

-OpenFOAM website giving more instructions: https://openfoam.org/download/source/



