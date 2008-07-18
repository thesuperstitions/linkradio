I-Logix-RPY-Archive version 8.0.9 C++ 893629
{ IProject 
	- _id = GUID 476e8783-88fe-4d09-bc9c-2b1f1afff97f;
	- _myState = 8192;
	- _properties = { IPropertyContainer 
		- Subjects = { IRPYRawContainer 
			- size = 1;
			- value = 
			{ IPropertySubject 
				- _Name = "General";
				- Metaclasses = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Model";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "ModelCodeAssociativityFineTune";
								- _Value = "RoundTrip";
								- _Type = Enum;
								- _ExtraTypeInfo = "Bidirectional,RoundTrip,CodeGeneration";
							}
						}
					}
				}
			}
		}
	}
	- _name = "InterprocessPubSub";
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "InterprocessPubSub.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "InterprocessPubSub";
		- _id = GUID fe9b4c43-5f34-4849-9179-e43d171f76ef;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "DefaultComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "DefaultComponent";
		- _id = GUID a0ffa620-ed13-4221-a4cf-86891ec07894;
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
			- fileName = "InterprocessPubSub";
			- _id = GUID fe9b4c43-5f34-4849-9179-e43d171f76ef;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IDiagram 
			- fileName = "Model1";
			- _id = GUID 5e84689c-5511-4022-869e-78a5591c51e5;
		}
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID a0ffa620-ed13-4221-a4cf-86891ec07894;
		}
	}
}

