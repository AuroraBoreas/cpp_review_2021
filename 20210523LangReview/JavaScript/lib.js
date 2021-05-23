/*
JavaScript, meta review

@ZL, 20210523

*/ 

const cls = require('./cls.js');

function variableDemo() {
    /*
    @ variable
    ===
    * concept: box
    * pattern: TNV
    * feature:
        - primitive types(meta types)
            $ char
            $ short
            $ int
            $ long

            $ float
            $ double
            $ long double

            $ [x]byte
            $ boolean
            $ [x]decimal

        - type traits(reflect)
        - type conversion
            $ implicit vs explicit
            $ downcasting vs upcasting
            $ narrowing

        - initialization
            $ resource acquisition is initialization
            $ copy assignment operator
            $ copy ctor
            $ list initialization

        - ByVal, ByRef, ByPtr
            $ ByVal
                ~ lvalue
                ~ rvalue
            $ ByRef
                ~ r-ref
                ~ l-ref
            $ ByPtr
                ~ raw pointer
                ~ array
                ~ smart pointer

        - variable template
            $ generic

        - keywords
            $ storage
                ~ static
                ~ const
                    % const and variable
                    % const and pointer
                    % const and function
                ~ extern
                ~ register
                ~ auto
            
            $ compile time
                ~ constexpr
                ~ string literal

        - parameter vs argument
            $ argument means actual variable
            $ parameter means placeholder variable
    ===    
    */ 
};

function functionDemo() {
    /*
    @ function
    ===
    * concept: black box
    * pattern: TNP
    * feature:
        - regular
        - [x]anonymous
        - lambda
        - [x]immediate
        
        - function pointer
        - [x]decorator
        - [x]generator
        - [x]function in function
        - class in function

        - return_type
            $ ByVal
            $ ByRef
            $ ByPtr
        
        - func_name
            $ overload
            $ operator overload
            $ function template

        - args
            $ ByVal
            $ ByRef
            $ ByPtr

        - keywords
            $ inline vs macro
            $ const
            $ constexpr
            $ noexcept
            $ [[deprecated]]
    ===
    */ 
};

function statementDemo() {
    /*
    @ statement
    ===
    * concept: link
    * pattern: symbol
    * feature:
        - arithmetic
            $ +, -, *, /, %
            $ (prefix)++, --; (postfix) ++, --

        - relational
            $ ==, !=
            $ >, >=
            $ <. <=

        - logic
            $ !
            $ &&
            $ ||

        - access
            $ (*ptr).
            $ ptr->

        - bitwise
            $ ~
            $ <<, >>
            $ &, |, ^

        - assign
            $ T var_name = val;
            $ T var_name(val);
            $ T var_name{val};
            $ T var_name = T(val);
            $ T var_name = T{val};

        - cast
            $ dynamic_cast
            $ static_cast
            $ const_cast
            $ reinterpret_cast
            $ C-style cast

        - op
            $ new
            $ delete

        - op
            $ .
            $ ,
            $ ;
            $ ()
            $ []
            $ {}
            $ <>

    ===
    */

};

function controlflowDemo() {
    /*
    @ controlflow
    ===
    * concept: branch
    * pattern: branch
    * feature:
        - if...else if...else
        - switch...case...default
        - try...catch...
    ===
    
    */ 

};

function loopDemo() {
    /*
    @ loop
    ===
    * concept: circle
    * pattern: circle
    * feature:
        - for(;;)
        - for(:)
        - while
        - do...while 
    ===
    
    */ 
};

function classDemo() {
    /*
    @ class
    ===
    * concept: sim
    * pattern: sim
    * feature:
        - Abstract
        - Encapsulation
        - Inheritance
            $ is-a
            $ has-a

        - Polymorphism

    * structure:
        ^ default ctor
        ^ default dtor
        ^ copy ctor
        ^ copy assignment operator
        ^ move ctor
        ^ move assignment operator

    * principles:
        # SRP
        # OCP
        # LSP
        # ISP
        # DIP
        # Delimiter principle

    * keywords:
        $ default
        $ explicit (operator opol for type conversion)
        $ override
        $ virtual
        $ =0 (abstract vs concret; abstract class is not allowed to create obj in C++)
    
    * privilage:
        % private
        % public
        % friend

    * other:
        & class vs struct vs enum
        & class template
        & dependency injection
        & class in class? 
    ===
    */ 

};

function datastructureDemo() {
    /*
    @ datastructure
    ===
    * concept: container
    * pattern: container
    * feature:
        - seq
            $ array -> fixed size
            $ vector
            $ list
            $ forward_list
            $ deque

        - adaptor
            $ stack
            $ queue
            $ priority_queue

        - associative
            $ map
            $ multimap
            $ set
            $ multiset

        - unordered associative
            $ unordered_set
            $ unordered_multiset
            $ unordered_map
            $ unordered_multimap
    ===
    */ 

};

function algorithmDemo() {
    /*
    @ algorithm
    ===
    * concept: calculation methods
    * pattern: world map of STL algorithm
    * feature:
        - permutation
        - queries
            ^ value queries
                $ count
                $ transform_inclusive_scan
                $ transform_exclusive_scan
                $ inclusive_scan
                $ exclusive_scan

            ^ property queries
            ^ search
            ^ 2-ranges properties

        - secrete runes
            $ *_n
            $ *_if
            $ *_copy
            $ stable_*
            $ is_*
            $ is_*_until

        - movers
        - lone island
        - raw memory 
        - value modifier
        - structure changer
    ===
    */

};