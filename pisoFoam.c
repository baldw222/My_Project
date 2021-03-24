1  /*–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––*\\
2    =========                 |
3    \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
4     \\\\    /   O peration     |
5      \\\\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
6       \\\\/     M anipulation  |
7  ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––-
8  License
9      This file is part of OpenFOAM. 
10  
11      OpenFOAM is free software: you can redistribute it and/or modify it
12      under the terms of the GNU General Public License as published by
13      the Free Software Foundation, either version 3 of the License, or
14      (at your option) any later version. 
15  
16      OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
17      ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
18      FITNESS FOR A PARTICULAR PURPOSE.   See the GNU General Public License
19      for more details. 
20  
21      You should have received a copy of the GNU General Public License
22      along with OpenFOAM.   If not, see <http://www.gnu.org/licenses/>. 
23  
24  Application
25      pisoFoam
26  
27  Description
28      Transient solver for incompressible, turbulent flow, using the PISO
29      algorithm. 
30  
31      Sub-models include:
32      - turbulence modelling, i.e.  laminar, RAS or LES
33      - run-time selectable MRF and finite volume options, e.g.  explicit porosity
34  
35  \\*–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––*/
36  
37  #include "fvCFD.H"
38  #include "singlePhaseTransportModel.H"
39  #include "turbulentTransportModel.H"
40  #include "pisoControl.H"
41  #include "fvOptions.H"
42  
43  // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
44  
45  int main(int argc, char *argv[])
46  {
47      #include "postProcess.H"
48  
49      #include "setRootCaseLists.H"
50      #include "createTime.H"
51      #include "createMesh.H"
52      #include "createControl.H"
53      #include "createFields.H"
54      #include "initContinuityErrs.H"
55  
56      turbulence->validate();
57  
58      // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
59  
60      Info<< "\\nStarting time loop\\n" << endl;
61  
62      while (runTime.loop())
63      {
64          Info<< "Time = " << runTime.timeName() << nl << endl;
65  
66          #include "CourantNo.H"
67  
68          // Pressure-velocity PISO corrector
69          {
70              #include "UEqn.H"
71  
72              // ––– PISO loop
73              while (piso.correct())
74              {
75                  #include "pEqn.H"
76              }
77          }
78  
79          laminarTransport.correct();
80          turbulence->correct();
81  
82          runTime.write();
83  
84          Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
85              << "  ClockTime = " << runTime.elapsedClockTime() << " s"
86              << nl << endl;
87      }
88  
89      Info<< "End\\n" << endl;
90  
91      return 0;
92  }
93  
94  
95  // ************************************************************************* //
