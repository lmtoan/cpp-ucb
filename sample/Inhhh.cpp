Class Base
{
        private:
        int     base_private;

        protected:
        int     base_protected;

        public:
        int     base_public;
}

class   Publicly_Derived : public Base
{
        private:
        int     derived_private;

        protected:
        int     derived_protected;

        public:
        int     derived_public;

        void    member_function();
}

void    Publicly_Derived::member_function()
{
        derived_private = 0;    // All OK: we're a member function.
        derived_protected = 0;
        derived_public = 0;

        //base_private = 0;     // Forbidden.
        base_protected = 0;     // OK: public derivation.
        base_public = 0;        // OK: public derivation.
}


class   Privately_Derived : private Base
{
        private:
        int     derived_private;

        protected:
        int     derived_protected;

        public:
        int     derived_public;

        void    member_function();
}

void    Privately_Derived::member_function()
{
        derived_private = 0;    // All OK: we're a member function.
        derived_protected = 0;
        derived_public = 0;

        //base_private = 0;     // Forbidden.
        base_protected = 0;     // OK: public derivation.
        base_public = 0;        // OK: public derivation.
}

void main()
{
        Base                    b;
        PubliclyDerived         pubd;
        PrivatelyDerived        privd;

        //b.base_private = 0;   // Forbidden.
        //b.base_protected = 0; // Forbidden.
        b.base_public = 0;      // OK.

        pubd.derived_public = 0;        // OK.
        //pubd.derived_protected = 0;   // Forbidden.
        //pubd.derived_private = 0;     // Forbidden.
        pubd.base_public = 0;           // OK: public derivation.
        //pubd.base_protected = 0;      // Forbidden.
        //pubd.base_private = 0;        // Forbidden.

        privd.derived_public = 0;       // OK.
        //privd.derived_protected = 0;  // Forbidden.
        //privd.derived_private = 0;    // Forbidden.
        //privd.base_public = 0;        // Forbiden: private derivation.
        //privd.base_protected = 0;     // Forbidden.
        //privd.base_private = 0;       // Forbidden.
}


class Graph
{
        public:
        Graph();        
                // Return 0 for failure, 1 for success.
        int     AddNode( ... );
        int     AddEdge( ... );
        int     RemoveNode( ... );
        int     RemoveEdge( ... );      

        int     PathBetween(src_node, second_node);
        void    print();
}

        // Tree is a private derivation from Graph.

class Tree : private Graph
{
        public:
                // Return 0 for failure, 1 for success.
                // These functions must ensure that the object
                // remains a tree.
        int     AddNode( ... );
        int     AddEdge( ... );
        int     RemoveNode( ... );
        int     RemoveEdge( ... );      

        int     PathBetween(src_node, second_node);
        void    print() { this->Graph::print(); };
}


void    main()
{
        Graph   g;
        Tree    t;

        g.AddEdge(...);
        t.AddEdge(...);

                // The following member function invocation is
                // disallowed because of the private derivation.
                // If it were allowed (via public derivation),
                // it might be possible to add edges to t or 
                // remove edges from t in such a way that it is
                // no longer a tree, but still an ordinary graph.

        // t.Graph::AddEdge(...);
}


class   Vehicle
{
        public:
        int     n_psgr;
        char    color[80];
        float   fuel_capacity;
        float   fuel_level;

        void    print();        
}

class   House
{
        public:
        char    color[80];
        int     square_footage;
        float   refrigerator_capacity;
        float   counterspace;

        void    print();
}

class   MotorHome : public Vehicle, public House
{
}



