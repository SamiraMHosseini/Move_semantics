//Samira_CSC562

class X
{
public:

	//Big Six

	//Constructor---------------------------------One------------------------------------
	X()
	{
		this->m_pResource = new std::vector<int>();
	}

	//Copy constructor-----------------------------Two-----------------------------------
	X(X const& rhs)
	{

		/* [...]
		 Make a clone of what rhs.m_pResource refers to.
		 Destruct the resource that m_pResource refers to.
		 Attach the clone to m_pResource.
		 [...]*/

		 //Delete the current resource 
		delete this->m_pResource;
		//Deep Copy (allocate new memory)
		this->m_pResource = new std::vector<int>();
		//Make a clone
		*this->m_pResource = *rhs.m_pResource;

	}

	//Copy assignment-------------------------------Three-------------------------------- 
	X& operator=(X const& rhs)
	{
		/* [...]
		 Make a clone of what rhs.m_pResource refers to.
		 Destruct the resource that m_pResource refers to.
		 Attach the clone to m_pResource.
		 [...]*/

		if (this != &rhs)
		{
			//Delete the current resource 
			delete this->m_pResource;
			//Deep Copy (allocate new memory)
			this->m_pResource = new std::vector<int>();
			//Make a clone
			*this->m_pResource = *rhs.m_pResource;

		}
		return *this;


	}
	//Move assignment--------------------------------Four---------------------------------- 
	X& operator=(X&& rhs)
	{
		/* Move semantics : exchange content between thisand rhs
		[...]
		 swap this->m_pResource and rhs.m_pResource
		[...]  */

		if (this != &rhs)
		{
			//Delete(free) the current resource
			delete this->m_pResource;
			//Transfer ownership of rhs.m_pResource to m_pResource
			this->m_pResource = rhs.m_pResource;
			//Do not foget this step otherwise  m_pResource would be left as a dangling pointer when rhs goes out of scope
			rhs.m_pResource = nullptr;
		}
		return *this;


	}
	//Move constructor--------------------------------Five----------------------------------  
	X(X&& rhs)
	{
		/* Move semantics : exchange content between thisand rhs
		[...]
		 swap this->m_pResource and rhs.m_pResource
		[...]  */

		//Transfer ownership of rhs.m_pResource to m_pResource
		this->m_pResource = rhs.m_pResource;
		//Do not foget this step otherwise  m_pResource would be left as a dangling pointer when rhs goes out of scope
		rhs.m_pResource = nullptr;



	}

	//Destructor----------------------------------Six----------------------------------  
	~X()
	{
		delete this->m_pResource;
	}


	void Print(const char* const str)
	{
		Trace::out("---Print %s's vector items---\n", str);
		if (this->m_pResource != nullptr)
		{
			for (auto item : *this->m_pResource)
			{
				Trace::out("%d \n", item);
			}
		}
		else
			Trace::out("%s is Null\n", str);

	}
	void Initialize(size_t size, int initialize_value)
	{

		for (size_t i{}; i < size; ++i)
		{
			this->m_pResource->push_back(initialize_value++);

		}
	}

private:
	//The resource
	std::vector<int>* m_pResource;
};

int main()
{
	//Create an object of X
	X a;
	//Initialize a vector of size 5 with starting value of 10
	a.Initialize(5, 10);
	a.Print("a");

	//Create an object of X
	X b;
	//Initialize a vector of size 7 with starting value of 0
	b.Initialize(7, 0);
	b.Print("b");

	//Copy assignment
	Trace::out("Copy assignment b = a\n");
	b = a; // This assignment will invoke the copy assignment
	b.Print("b");
	a.Print("a");


	//Move assignment
	Trace::out("Move assignment b = a\n");
	b = std::move(a); // This assignment will invoke the move assignment
	b.Print("b");
	a.Print("a");

	X c;
	//Initialize a vector of size 5 with starting value of 20
	c.Initialize(5, 20);
	c.Print("c");
	b.Print("b");


	//Move assignment
	Trace::out("Move assignment c = b\n");
	c = std::move(b);// This assignment will invoke the move assignment
	c.Print("c");
	b.Print("b");

}

// ---  End of File ---

