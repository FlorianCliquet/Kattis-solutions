#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef tree<string,         /* key                */
         null_type,   /* mapped             */
         less<string>,   /* compare function   */
         rb_tree_tag, /* red-black tree tag */
         tree_order_statistics_node_update> tr;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    tr male, female;
    int choice, gender;
    int count = 0;
    string name, a, b;
    cin >> choice;
    while (choice)
    {
    	switch(choice)
    	{
	    	case 1:
	    	{
	    		cin >> name >> gender;
				gender == 1 ? male.insert(name) : female.insert(name);
	    		break;
	    	}
	    	case 2:
	    	{
	    		cin >> name;
	    			auto it = male.lower_bound(name);
	    			if (*it == name)
	    				male.erase(male.lower_bound(name));
	    			else
	    				female.erase(female.lower_bound(name));
	    		break;
	    	}
	    	case 3:
	    	{
	    		cin >> a >> b >> gender;
	    		switch(gender)
	    		{
	    			case 0:
	    			{
	    				count = male.order_of_key(b) - male.order_of_key(a) + female.order_of_key(b) - female.order_of_key(a);
	    				break;
	    			}
	    			case 1:
	    			{
	    				count = male.order_of_key(b) - male.order_of_key(a);
	    				break;
	    			}
	    			case 2:
	    			{
	    				count = female.order_of_key(b) - female.order_of_key(a);
	    				break;
	    			}
	    		}
	    		cout << count << "\n";
	    		break;
	    	}
    	}
    	cin >> choice;
    }
    return 0;
}