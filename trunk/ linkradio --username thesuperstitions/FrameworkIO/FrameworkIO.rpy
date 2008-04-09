I-Logix-RPY-Archive version 8.0.9 C++ 893629
{ IProject 
	- _id = GUID 976474ab-3a8a-4fb6-9a79-1176ddde997f;
	- _myState = 8192;
	- _properties = { IPropertyContainer 
		- Subjects = { IRPYRawContainer 
			- size = 1;
			- value = 
			{ IPropertySubject 
				- _Name = "CPP_CG";
				- Metaclasses = { IRPYRawContainer 
					- size = 3;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Class";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "SpecificationProlog";
								- _Value = "#ifndef DtIFSPEC1516
#define DtIFSPEC1516
#endif";
								- _Type = MultiLine;
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "Configuration";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "ContainerSet";
								- _Value = "STLContainers";
								- _Type = Enum;
								- _ExtraTypeInfo = "OMContainers, STLContainers, OMUContainers";
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "File";
						- Properties = { IRPYRawContainer 
							- size = 2;
							- value = 
							{ IProperty 
								- _Name = "ImplementationHeader";
								- _Value = "//*********************************************************************************  
//
//	File:				$FullModelElementName  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		$Login  
//
//!	Date of createion:	$CodeGeneratedDate    
//
//	Description:		  
//
//**********************************************************************************
";
								- _Type = MultiLine;
							}
							{ IProperty 
								- _Name = "SpecificationHeader";
								- _Value = "//*********************************************************************************  
//
//	File:				$FullModelElementName  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		$Login  
//
//!	Date of createion:	$CodeGeneratedDate    
//
//	Description:		  
//
//**********************************************************************************
";
								- _Type = MultiLine;
							}
						}
					}
				}
			}
		}
	}
	- _name = "FrameworkIO";
	- _lastID = 1;
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "Framework.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "Framework";
		- _id = GUID 60248ea5-0dec-4f7a-b68d-4395e419a607;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "DefaultComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "DefaultComponent";
		- _id = GUID 0cee5742-c971-48b3-8364-c37a34c4304b;
	}
	- Multiplicities = { IRPYRawContainer 
		- size = 4;
		- value = 
		{ IMultiplicityItem 
			- _name = "1";
			- _count = -1;
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
		- size = 1;
		- value = 
		{ ISubsystem 
			- fileName = "Framework";
			- _id = GUID 60248ea5-0dec-4f7a-b68d-4395e419a607;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 0;
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID 0cee5742-c971-48b3-8364-c37a34c4304b;
		}
	}
}

