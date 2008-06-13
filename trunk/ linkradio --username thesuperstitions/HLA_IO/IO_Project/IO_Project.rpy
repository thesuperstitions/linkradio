I-Logix-RPY-Archive version 8.0.9 C++ 893629
{ IProject 
	- _id = GUID 309ae1e8-af51-489e-a066-d24f2aa097b9;
	- _myState = 8192;
	- _name = "IO_Project";
	- _lastID = 2;
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "framework.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "framework";
		- _id = GUID 60248ea5-0dec-4f7a-b68d-4395e419a607;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "DefaultComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "DefaultComponent";
		- _id = GUID 959aecfe-ee33-41c4-9932-c789f9c1cf63;
	}
	- Multiplicities = { IRPYRawContainer 
		- size = 4;
		- value = 
		{ IMultiplicityItem 
			- _name = "1";
			- _count = 9;
		}
		{ IMultiplicityItem 
			- _name = "*";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "0,1";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "1..*";
			- _count = -1;
		}
	}
	- Subsystems = { IRPYRawContainer 
		- size = 3;
		- value = 
		{ ISubsystem 
			- fileName = "framework";
			- _id = GUID 60248ea5-0dec-4f7a-b68d-4395e419a607;
		}
		{ ISubsystem 
			- fileName = "FrameworkTest";
			- _id = GUID 915edaf7-df19-4281-9d22-aec45244fbf3;
		}
		{ ISubsystem 
			- fileName = "boost_1";
			- _id = GUID 5f8a27f7-316e-41a4-81da-d140b34944e4;
			- _name = "boost";
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IDiagram 
			- fileName = "Model1";
			- _id = GUID 6f4a7af5-ec9f-4b29-b767-d3dbb8cd0635;
		}
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID 959aecfe-ee33-41c4-9932-c789f9c1cf63;
		}
	}
}

