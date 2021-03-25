# Software Abstract:
OpenFoam is free open source C++ based software used for Computational Fluid Dynamics (CFD), it is utilized all throughout the STEM field to find flaws in designs and visulize certain properties we cannot see with the naked eye. It has been widely used by car manfufacturers and other companies to model cars and other modes of transportation to visualize the aerodynamics of the vehicle, and to improve upon it. 


# Installation/ Compilation
1. clone the repo for both the OpenFoam software and the third party example scripts using commands:
    - git clone https://github.com/OpenFOAM/OpenFOAM-8.git
    - git clone https://github.com/OpenFOAM/ThirdParty-8.git 
    - I have also added a install script titled "install.sb" in the main repo, this will create two new directories.

2. Navigate into the OpenFOAM-8 directory and source and set the enviornment variables using:
    - source (Your home directory)/OpenFOAM-8/etc/bashrc (If using bash)
    - source (Your home directory)/OpenFOAM-8/etc/cshrc  (If using tcsh)

3. To compile the software you just have to use the command:
    - ./Allwmake to compile in serial (Takes several hours, not recomended)
    - ./Allwmake -j to compile in parallel with all available cores and hyperthreads

# Example Code
I found examples for Formula 1 aerodynamics but they were for a different CFD software called Ansys, I tried to get the code to work for OpenFOAM but it was challenging converting to ascii and I ran out of time. Luckily these repos have examples you can run.

I first made a new directory inside the OpenFOAM-8 repo just to keep everything in one place titled "OpenFoamExamples" and in that directory there is a README file explaining the project and an sb file titled "flame.sb" which will copy over a directory from the repo and will run the example. 

# References
Github page for OpenFoam version 8: https://github.com/OpenFOAM/OpenFOAM-8
Github page for the Third Party example scripts: https://github.com/OpenFOAM/ThirdParty-8
OpenFOAM website giving more instructions: https://openfoam.org/download/source/



