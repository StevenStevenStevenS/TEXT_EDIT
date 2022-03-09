// TEXT-EDIT API.c
// I am very happy to get to make this. If you are using this, thank you! :)
#include <stdio.h>      // For input/output


#include <stdbool.h>    // For booleans

/*
If [
if :
    Could be anything
    // Learn how to talk when there's conflict
if {} afterwards
    Then it's a StoryNode' (Most likely)

    Create a storyNode with the contents
*/

// PARSER
// Tag -
// But this isn't a keyword

struct Other {
    BSTnode* bst;
};

struct StoryNode {
    int nextsNumber;
    int before_funcsNumber;
    int after_funcsNumber;
    int markersNumber;
    int functionsNumber;

    BSTnode* bst;
};

struct Audio {
    

    BSTnode* bst;
};

struct Function {
    

    BSTnode* bst;
};


# define TAG        1
# define STORYNODE  2
# define NEXT       3
# define INPUT      4
# define AUDIO      5
# define MARKER     6
# define FUNCTION   10


// AST


typedef struct info {

    BSTnode* BSTcurrentParent;

    int nextsNumber;
    int before_funcsNumber;
    int after_funcsNumber;
    int markersNumber;
    int functionsNumber;


    char field[4];

    bool inQuotes;
    bool typeDefined;

    bool inBrackets;
    bool WatchingColonList;
    bool afterBracketsWaiting;
    bool inCurly;
    

    
    int currentField;

    int type;
    int field;
    char* value;

    
    char i;
};

LLnode LLstart;
LLnode* LLcurrent;
LLnode* LLend;

LLnode subnodeStart;
LLnode current;
LLnode subnodeEnd;


/*typedef struct nodeLLnode {
    char* type;
    struct LLnode* next;
};*/

char token[100];


// File to open
//FILE *fp;

// Get the chars one at a time
int main() {
    // Lexer

    return 0;
}

void lexer(char f[]) {
    // Preamble
    FILE *fp;
    char ch;

    // Open file f
    fp = fopen(f, "r");

    // Lexer
    while( (ch = getc(fp)) != EOF) {
        printf("%c",ch);
    
        // Interpret what it means

        // Do quotes here
        if (ch == '"' || ch == '\'') {
            //todo 1
            // Check how to check if something is normal quote
        }

        if (lastch == '/' && ch == '/' && !current.inQuotes) {
            // Probably get rid of it, unless I can find a suitable place to put it
            //todo 1
        }

        if (lastch == '/' && ch == '*' && !current.inQuotes) {
            // "
            //todo 1
        }

        if (current.inBrackets) {
            
            if (current.watchingColonList) {
                takingColonInput(ch);
            }
            
            // Get name

            // In the three below, we're watching to see what type the node is
            // Once we find out what it is, we can put it on the right track (while still needing to see if there are colons; what comes after the colons; and if there's anything in brackets)
            if (!current.typeDefined) {
                if (current.afterFirst) {

                }

                if (ch == ' ') {
                    if (sizeof(token) > 0) {    // todo: If there's some text (not ' ' or '\t' or '\n') before a ' ', '\t', or '\n'; declare a node of the given type; (UNLESS it's a tag: tags can have any name (text inside brackets), which makes them a little less obviously defined.)
                        int t = type(token); // type and nodealloc function home
                        nodealloc(t);

                        //Tag = no spaces in name
                        //Tag id can be 1T, 2T, etc.


                        // We're now looking for an id #, or to see if this first blob is really a node type    //todo
                        // Or potentially a next/marker. (These should have their own id's)
                        
                        // todo 1: mark that this node has a type (UNLESS the spaces are unnecesary)

                        current.afterFirst = true;
                    }
                }

                if (ch == ':') {
                    //todo 1: Whatever the last thing was is declared as the id (UNLESS it's a next node, tag??- (nope), or marker)
                    // We're now watching the colonList.
                    current.watchingColonList = true;
                }

                

                if (ch == ']') {
                    // waiting after brackets = true

                    current.afterBracketsWaiting = true;    //Todo
                    current.inBrackets = false;
                    current.type = 1;   // todo

                    // mark that the node has "X" type and "Y" id
                }

                

                token[i] = ch;  // todo 1: i --> supposed to be last space
                token[i+1] = '\0';
            }
        }

        if (afterBrackets == true) {
            if (ch == '{') {
                inCurly = true;
            } else {
                // This is the same code as in takingCurlyInput > ch == '}'

                // Delete subnodeCurrent LLnode
                subnodeStart = subnodeCurrent.next;
                free(subnodeCurrent);
                subnodeCurrent = subnodeStart;
            }
        }

        if (current.inCurly) {
            takingCurlyInput(ch);
        }

        if (ch == '[') {
            current.inBrackets = true;
        }

        if (ch == '{') {
            current.inCurly = true;
        }

        else if (ch != ' ' && ch != '\t' && ch != '\n') {
            // There's only one/two instance in which I use spaces.
            // Otherwise, they can be gotten rid of, or something.
        }

        else if (ch == '"') {

        }
    }
}


// todo #: make sure Other function and AssignToField are made into pointer vars,

int (*interpretField)(char* field);
void (*assignToField)(int fint, char** value);    //todo
void (*typeTreeAlloc)(void** rootPtr);

int sublevel = 0;

int type(char* str) {
    if (strcmp( str, "Tag") == 0) {
        *assignToField = &AssignToOtherField;
        *interpretField = &interpretOtherField;
        *typedTreeAlloc = &otheralloc;

        return TAG;
    } else if (strcmp( str, "StoryNode") == 0) {
        *assignToField = &AssignToStoryNodeField;
        *interpretField = &interpretStoryNodeField;
        *typedTreeAlloc = &storynodealloc;
        
        return STORYNODE;
    } else if (strcmp( str, "Next") == 0) {
        if (sublevel) {
            *assignToField = &AssignToIntNextField;
            *interpretField = &interpretNextField;
   
            *typedTreeAlloc = &intnextalloc;
        } else {
            *assignToField = &AssignToExtNextField;
            *interpretField = &interpretNextField;
   
            *typedTreeAlloc = &extnextalloc;
        }

        return NEXT;
    } else if (strcmp( str, "Input") == 0) {
        *assignToField = &AssignToOtherField;
        *interpretField = &interpretInputField;
        *typedTreeAlloc = &otheralloc;

        return INPUT;
    } else if (strcmp( str, "Audio") == 0) {
        *assignToField = &AssignToAudioField;
        *interpretField = &interpretAudioField;
        *typedTreeAlloc = &otheralloc;

        return AUDIO;
    } else if (strcmp( str, "Marker") == 0) {
        if (sublevel) {
            *assignToField = &AssignToIntMarkerField;
            *interpretField = &interpretMarkerField;
   
            *typedTreeAlloc = &intmarkeralloc;    
        }

        *assignToField = &AssignToExtMarkerField;
        *interpretField = &interpretMarkerField;
        *typedTreeAlloc = &extmarkeralloc;

        return MARKER;
    } else if (strcmp( str, "Function") == 0) {
        *AssignToField = &AssignToOtherField;
        *interpretField = &interpretOtherField;
        *typedTreeAlloc = &otheralloc;

        return FUNCTION;
    }

    printf("Error: %s is not a valid node type.", str);
    return NULL;
}

#define SIZEOFOTHERS = 3

#define SIZEOFTAG = 3
#define SIZEOFSTORY = 6
#define SIZEOFINTNEXT = 3
#define SIZEOFEXTNEXT = 5

#define SIZEOFINPUT = 3
#define SIZEOFAUDIO = 3
#define SIZEOFINTMARKER = 3
#define SIZEOFEXTMARKER = 5

#define SIZEOFFUNC = 5


otheralloc(BSTnode** rootPtr) {
    ptr = (BSTnode*)calloc(BSTnode, SIZEOFOTHERS);
    //Structure the tree
    ptr[0]->left = ptr[2];
    ptr[0]->right = ptr[1];

    *rootPtr = ptr[0];
}

storynodealloc(BSTnode** rootPtr) {
    ptr = (BSTnode*)calloc(BSTnode, SIZEOFSTORY);
    //Structure the tree
    ptr[0]->left = ptr[2];
    ptr[0]->right = ptr[1];
        ptr[1]->left = ptr[4];
        ptr[1]->right = ptr[3];
            ptr[3]->left = ptr[6];

    *rootPtr = ptr[0];
}

intnextalloc(BSTnode** rootPtr) {
    ptr = (BSTnode*)calloc(BSTnode, SIZEOFINTNEXT);
    //Structure the tree
    ptr[0]->left = ptr[2];
        ptr[2]->left = ptr[1];
            ptr[1]->left = ptr[3];

    *rootPtr = ptr[0];
}

extnextalloc(BSTnode** rootPtr) {
    ptr = (BSTnode*)calloc(BSTnode, SIZEOFEXTNEXT);
    //Structure the tree
    ptr[0]->left = ptr[2];
    ptr[0]->right = ptr[1];
        ptr[1]->left = ptr[3];
            ptr[3]->left = ptr[4];

    *rootPtr = ptr[0];
}

intmarkeralloc(BSTnode** rootPtr) {
    ptr = (BSTnode*)calloc(BSTnode, SIZEOFINTMARKER);
    //Structure the tree
    ptr[0]->left = ptr[2];
        ptr[2]->left = ptr[1];

    *rootPtr = ptr[0];
}

extmarkeralloc(BSTnode** rootPtr) {
    ptr = (BSTnode*)calloc(BSTnode, SIZEOFEXTMARKER);
    //Structure the tree
    ptr[0]->left = ptr[2];
    ptr[0]->right = ptr[1];
        ptr[1]->left = ptr[4];
            ptr[4]->left = ptr[3];

    *rootPtr = ptr[0];
}


// Allocate space for a specific node type






//#include <std??.h>
//#include <???>


int fi;


*fp = FILE *fopen(const char *filename, const char *mode);



int takingColonInput(char ch) {
    
    // if it's not in quotes:   todo 1: does this really work? Where should this be put overall?
    if (ch == '"' || ch == '\'') {  // Todo: make sure the ch before was not \ (if it's possible for that to make this an escape char) also make sure \' means ' and not just \'
        inQuotes = !inQuotes        // I have some work to do.
    } else if (inQuotes) {  // Todo: figure out this in-quote buisness

    // check on above, interpreting, creating node/BST

    } else if(ch == '{') {
        // todo 1
        // We're in a list, so each node will be added to the last's "right".
    } else if (ch == '[') {
        // Now it's in subnode
        // I should add it to the subnode queue and put it through the machine.
        // ...Which might mean that I have to save my current variable values, and that I should make a place for this node to start.

        current =  (levelinfo*)malloc(levelinfo);

        // todo 2: a little bit more info is needed to transfer to this node from the last node



        // So we're in the same overall LLnode Binary Search Tree, but in a different pos on it.
        // Where pos?

        // Drop all other things:
        // Say this is "inBrackets"
        current.inBrackets = true;

        // Try to skim ahead a little bit to see what this node is,
        // So we know where to put it in the BST. // OR: search back. If we know what the last parent node was in the tree, we can use it's type to define where the subnode should go. we  as a part of the previous linked list, 


    } else if (ch == ',') {
        fi ++;  // Field i
        // Assign the token value to the correct slot
        
        //todo 1: edit
        assign_to_field_n(object, currentField, value) // or
        assign_to_field(type, )
    } else if (ch != ' ') {
        token[0] = ch;  // 0 --> supposed to be last space
        token[0+1] = '\0';  // todo 2: make sure
    }
    // Is that a linked list?
    
}

typedef struct LLnode {
    void* data; //todo
    struct LLnode* next;
} LLnode;

typedef struct node {
    void* data; //todo
    struct node* left;
    struct node* right;
} BSTnode;


LLnode ASTstart;
LLnode* ASTcurrent;
LLnode* ASTend;

LLnode subStart;
LLnode subCurrent;
LLnode subEnd;

char token[];   // A small token string
char longToken[];   // A long token string

char field[];

//// Break

int takingCurlyInput(char ch) {
    int howMany = lastHowMany ++;

    
    if (ch == '"') {
        // todo 1
        // The story node structure is the first way, not the second way.
        // The user can optionally not put in a field name, but just a string, and the 
        // TEXT_EDIT API will know that it is field 1.
    }
    else if (ch != ' ' && ch != '\t' && ch != '\n') {

    }

    if (dec && ch == "=") {
        //token[0] = ch;  // 0 --> supposed to be last space
        //token[0+1] = '\0';
        /*todo 1*/field(token);    //Or...

        token = "";


        // NEW WAY:
        afterDecWaiting = true; // Rather make var equal to BSTnode for field
        currentField = getFieldNode(field(token));
    }

    if (value && ch == ';') {
        // value = token;
        InterpretField()
        /*todo 1*/assign_to_field(object, field, token);  // Notes: broken























        // In this, the values for this field are over. With ',' the values are still piling up (and they need to be stored)
        token = "";
    }


    if (ch == '[') {
        //inSubBrackets = true;
        //or
        
        //subLevel += 1;
        //inBrackets = true;
        
        
        // Node

        // todo: work this out
        // This should only be done for Next nodes, so I might be able to get away with the first.
        // Also don't want to overwrite any of the data I'm collecting for the first node

        // It's inside a next, or a custom mod to allow a different kind of node inside a node
    
        current =  (levelinfo*)malloc(levelinfo);
        current.inBrackets = true;
    
    }

    if (ch != ' ') {
        token[0] = ch;  // 0 --> supposed to be last space
        token[0+1] = '\0';  // todo 2: make sure
    }

    if (ch == '}') {
        inCurly = false;

        // todo 1: Make sure the subnode is freed from the subnode LL
    }
    
    if (ch == ',') {
        //todo 1
        //check for aditional nexts/markers
        value = token;
        InterpretField();
        assign_to_field(object, field, value);
    }
}


// And that these functions are referenced when the type is found out

// Bookmark

void assignToOtherField(int fint, char** value) {
    switch(fint) {
        BSTnode* grabBSTnode;
        char* ptr;

        case 1:
            grabBSTnode = getBSTnode(10);
            char* ptr = (char*)calloc(char, size);
            *ptr = value;

            grabBSTnode.data = ptr;
            break;
        case 2:
            // todo 1: read comments

            // Case 2 is actually for a next
            // So all of the things might need to be covered here?

            // OR, something else
            // or- another thought- this thing should be created somewhere else

            assignNext

            grabBSTnode = getBSTnode(101);
            // Store next's next-id
            // Start of next tree (which is only next_id and other value)
            int* ptr = (int*)malloc(int);
            *ptr = atoi(value);

            grabBSTnode.data = ptr;
            break;  // There should be one assigned after this, since it's a node.
            //                                                  -----        ----
    }
}

void assignToStoryNodeField(int fint, char** value) {
    switch(fint) {
        case 1:
            grabBSTnode = getBSTnode(10);
            char* ptr = (char*)calloc(char, size);
            //ptr = atoi(value);    // todo: check (that this is how you do this)
            *ptr = value;
            grabBSTnode.data = ptr;
            break;
        case 2:
            grabBSTnode = getBSTnode(101);
            char* ptr = (char*)calloc(char, size);
            *ptr = value;
            grabBSTnode.data = ptr;
            break;
        case 3:
            grabBSTnode = getBSTnode(100);
            // todo: nexts
            
            if (tokenfieldcounter == 0):
                assignFirst = true;
            else if (tokenfieldcounter > 0)
                assignNext = true;

            // Need to know if this is going in position 0, or 1,2,3,...etc.
            // 0 (First) is added differently than all of the others.

            /*ptr = (char*)calloc(char, size);
            ptr = value;
            break;*/
        case 4:
            getBSTnode(1001);
            //todo: how?
            current->before_funcs = value;
            break;
        case 5:
            getBSTnode(1010);
            //todo
            current->after_funcs = value;
            break;
    }
    grabBSTnode->data = ptr;
}

void assignToExtNextField(int fint, char** value) {
    switch(fint) {
        case 1:
            grabBSTnode = getBSTnode(10);
            int* ptr = (int*)malloc(int);
            *ptr = atoi(value);
            grabBSTnode.data = ptr;
            break;
        case 2:
            grabBSTnode = getBSTnode(101);
            int* ptr = (int*)malloc(int);
            *ptr = nextState(value);
            grabBSTnode.data = ptr;
            break;
        case 3:
            grabBSTnode = getBSTnode(1011);
            char* ptr = (char*)calloc(char, size);
            *ptr = value;
            grabBSTnode.data = ptr;
            break;
    }
}

void assignToIntNextField(int fint, char** value) {
    switch(fint) {
        case 1:
            grabBSTnode = getBSTnode(1);
            int* ptr = (int*)malloc(int);
            *ptr = atoi(value);
            grabBSTnode.data = ptr;
            break;
        case 2:
            grabBSTnode = getBSTnode(11);
            int* ptr = (int*)malloc(int);
            *ptr = nextState(value);
            grabBSTnode.data = ptr;
            break;
        case 3:
            grabBSTnode = getBSTnode(10);
            char* ptr = (char*)calloc(char, size);
            *ptr = value;
            grabBSTnode.data = ptr;
            break;
    }
}

void assignToAudioField(int fint, char** value) {
    switch(fint) {
        case 1:
            grabBSTnode = getBSTnode(10);
            ptr = (char*)calloc(char, size);
            //ptr = atoi(value);    // todo: check (that this is how you do this)
            ptr = value;
            break;
        case 2:
            // todo: start of marker tree
        case 3:
            // start of next tree (which is only next_id and other value)   //todo
    }
}


// INTERPRET FIELDS //

int interpretOtherField(char* field) {
    if (strcmp(field, "name") == 0)
        return 1;
    else if (strcmp(field, "next") == 0)
        return 2;
}

int interpretStoryField(char* field) {
    if (strcmp(field, "text") == 0)
        return 1;
    if (strcmp(field, "spirit") == 0)
        return 2;
    if (strcmp(field, "nexts") == 0)
        return 3;
    if (strcmp(field, "before_funcs") == 0)
        return 4;
    if (strcmp(field, "after_funcs") == 0)
        return 5;
    
}

int interpretNextField(char* field) {
    // It's possible to have two inits
    //
    // Not all Nexts have a name, and some of them will have the name first, and then the two cases
    // Actually: nevermind. That works out. I'll be able to tell
    // what the string is at once because of the colon.
    if (strcmp(field, "next") == 0)
        return 1;
    if (strcmp(field, "state") == 0)
        return 2;
    if (strcmp(field, "name") == 0)
        return 3;
}

int interpretInputField(char* field) {
    if (strcmp(field, "prompt") == 0)
        return 1;
    if (strcmp(field, "next") == 0)
        return 2;
}

int interpretAudioField(char* field) {
    if (strcmp(field, "audio") == 0)
        return 1;
    if (strcmp(field, "markers") == 0)
        return 2;
    if (strcmp(field, "next") == 0)
        return 3;
}

int interpretMarkerField(char* field) {
    if (strcmp(field, "time") == 0)
        return 1;
    if (strcmp(field, "caption") == 0)
        return 2;
    if (strcmp(field, "spirit") == 0)
        return 3;
    if (strcmp(field, "next") == 0)
        return 4;
}


// TRASH //

InterpretVal() {    // delete
    
}

int assignToField(fint, val) {   // value used to be valuestr
    struct T valueT = InterpretVal(valuestr);
    // Match 

    switch (fint) {
        case ID:
            current->id = atoi(value);
            break;
        case TYPE:
        case 1:
            if (current.type != FUNCTION) {
                grabBSTnode = getBSTnode(10);
                ptr = (char*)calloc(char, size);
                ptr = atoi(value);    // todo: check (that this is how you do this)
                grabBSTnode->data = ptr;
            } else {
                // If you keep adding to it
            }
            break;
        case 2:
            grabBSTnode = getBSTnode(101);
            // Store next's next-id
            // Start of next tree (which is only next_id and other value)
            ptr = (int*)malloc(int);
            
            else if(LLcurrent.type == STORYNODE) {
                ptr = (char*)calloc(char, size);
            } else if(LLcurrent.type == AUDIO) {
                // todo: start of marker tree
                ptr = (float*)malloc(float);
            }
            ptr = value;
            grabBSTnode->data = ptr;

            current->emotion = value;
            break;
        case 3:
            grabBSTnode = getBSTnode(100);
            else if(LLcurrent.type == STORYNODE) {
                // start of before function tree
                ptr = (char*)calloc(char, size);
            } else if(LLcurrent.type == AUDIO) {
                // start of next tree (which is only next_id and other value)   //todo
                ptr = (int*)malloc(int);
            }
            //todo: Next
            break;
        case 4:
            getBSTnode(1001);
            //todo
            current->before_funcs = value;
            break;
        case 5:
            getBSTnode(1010);
            //todo
            current->after_funcs = value;
            break;

        case 6:
            name
            break;
        case 1:
            LLcurrent->data->
            break;
    }


    // Match the field value with the field variable
    switch (current.type) {
        case TAG:
            switch () {

            }
            break;
        case STORYNODE:
            switch (field) {
                case 1:
                    LLcurrent->data->id = atoi(value);
                    break;
                case 2:
                    LLcurrent->data->text = value;
                    break;
                case 3:
                    LLcurrent->data->expression = value;
                    break;
                case 4:
                    LLcurrent->data->next = valueT.next;    //can't do yet
                    break;
                case 5:
                    LLcurrent->data->before = value;    // Really a string?
                    break;
                case 6:
                    LLcurrent->data->after = value;     // Really a string?
                    break;
            }
            break;
        case NEXT:
            switch (field) {
                case 1:
                    LLcurrent->data->next = atoi(value);
                    break;
                case 2:
                    LLcurrent->data->state = value;
                    break;
                case 3:
                    LLcurrent->data->name = value;
                    break;
            }
            break;
        case INPUT:
            switch (field) {
                case 1:
                    LLcurrent->data->prompt = value;
                    break;
                case 2:
                    LLcurrent->data->next = valueT.next;    //can't do yet
                    break;
            }
            break;
        case AUDIO:
            switch (field) {
                case 1:
                    LLcurrent->data->prompt = atoi(value);
                    break;
                case 2:
                    LLcurrent->data->audio = value;
                case 3:
                    LLcurrent->data->markers = value;   // Not a string
            }
            break;
        case MARKER:
            switch (field) {
                case 1:
                    LLcurrent->data->time = atof(valueT);
                    break;
                case 2:
                    LLcurrent->data->caption = value;
                    break;
                case 3:
                    LLcurrent->data->emotion = value;
                    break;
                case 4:
                    LLcurrent->data->next = value;  // Wrong type
                    break;
            }
            break;
        case FUNCTION:
            switch (field) {
                case 1:
                    LLcurrent->data->id = atoi(value);
                    break;
                case 2:
                    LLcurrent->data->name = value;
                    break;
                case 3:
                    LLcurrent->data->next = value;  // Wrong type
                    break;
            }
            break;
    }
}

void* nodealloc(int type, void** ptr) {
    switch(type) {
        case TAG:
            LLcurrent->type = TAG;
            LLcurrent->data = (BSTnode*)calloc(BSTnode, SIZEOFTAG);
            break;
        case STORYNODE:
            LLcurrent->type = STORYNODE;
            LLcurrent->data = (BSTnode*)malloc(sizeof(StoryNode));
            break;
        case NEXT:
            LLcurrent->type = NEXT;
            LLcurrent->data = (BSTnode*)malloc(sizeof(Next));
            break;
        case INPUT:
            LLcurrent->type = INPUT;
            LLcurrent->data = (BSTnode*)malloc(sizeof(Input));
            break;
        case AUDIO:
            LLcurrent->type = AUDIO;
            LLcurrent->data = (BSTnode*)malloc(sizeof(Audio));
            break;
        case MARKER:
            LLcurrent->type = MARKER;
            LLcurrent->data = (BSTnode*)malloc(sizeof(Marker));
            break;
        case FUNCTION:
            LLcurrent->type = FUNCTION;
            LLcurrent->data = (BSTnode*)malloc(sizeof(Function));  // Todo: case 7: or 10:?
            break;
    }

    if (type < idmin || type > idmax) {
        printf("Error: %d is not a valid type.", type); //todo - cant connectate type 
        return NULL;
    }
}

typedtreealloc() {

}