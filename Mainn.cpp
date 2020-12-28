#include<iostream>
using namespace std;
struct sp {
	int p = 0;
	string song;
	string* pName = new string[p];
	sp* next;
};
sp* spHead = NULL;
struct playlist2 {
	string pName;
	playlist2* next;
};
playlist2* head[20];
string title[100];
string singer[100];
double duration[100];
int p = 0;
int n = 0;
class song_collection {
public:
	void selection() {
		int option;
		char yn;
		do {
			cout << "----------Playlist----------" << endl;
			cout << "1. Add Songs\n2. Display Songs\n3. Delete Song" << endl;
			cout << "Select one option:";
			cin >> option;
			switch (option) {
			case 1:addSongs(); break;
			case 2:displaySongs(); break;
			case 3:deleteSongs(); break;
			default:cout << "Error!Invalid Input!" << endl;
			}
			cout << "Do you want to use song collection?(Y/N)";
			cin >> yn;
		} while (yn == 'Y' || yn == 'y');
	};
	void addSongs() {
		string sName;
		char yn;
		bool duplicate;
		do {
			duplicate = false;
			cout << "----------Creating Songs----------" << endl;
			cout << "Enter song name:";
			cin >> sName;
			if (n != NULL) {
				for (int i = 0; i <= n; i++)
					if (title[i] == sName) {
						duplicate = true;
						break;
					}
			}
			if (n == NULL || duplicate == false) {
				title[n] = sName;
				cout << "Enter singer:";
				cin >> singer[n];
				cout << "Enter duration:";
				cin >> duration[n];
				n += 1;
			}
			if (duplicate == true) {
				cout << "The song name is duplicated!" << endl;
			}
			cout << "Do you want to add Song?(Y/N):";
			cin >> yn;
		} while (yn == 'Y' || yn == 'y');
	};
	void displaySongs() {
		cout << "----------Display Songs----------" << endl;
		if (n != NULL) {
			cout << "Name" << "\tSinger" << "\tDuration   " << endl;
			for (int i = 0; i < n; i++) {
				cout << title[i] << "\t" << singer[i] << "\t" << duration[i] << endl;
			}
		}
		else {
			cout << "The list is empty.";
		}
	};
	void deleteSongs() {
		bool found;
		char yn;
		string sName;
		do {
			found = false;
			if (n != NULL) {
				cout << "----------Delete Songs----------" << endl;
				cout << "Enter Song Name:"; cin >> sName;
				for (int i = 0; i < n; i++) {
					if (title[i] == sName) {
						while (i != n) {
							title[i] = title[i + 1];
							singer[i] = singer[i + 1];
							duration[i] = duration[i + 1];
							i += 1;
						}
						found = true;
						break;
					}
				}
			}
			else {
				cout << "The list is empty!";
			}
			if (found == true) {
				n = n - 1;
				cout << "The song is deleted!";
			}
			cout << "Do you want to delete song?(Y/N):";
			cin >> yn;
		} while (yn == 'Y' || yn == 'y');
	};
	void playlistSearch() {};
};
class playlist {
public:
	song_collection sc;
	void selection() {
		int option;
		char yn;
		do {
			cout << "----------Playlist----------" << endl;
			cout << "1. Create Playlist\n2. View Playlist\n3. Add Songs\n4. View Songs\n5. Remove Songs" << endl;
			cout << "Select one option:";
			cin >> option;
			switch (option) {
			case 1:createPlaylist(); break;
			case 2:viewPlaylist(); break;
			case 3:addSongs(); break;
			case 4:viewSongs(); break;
			case 5:removeSongs(); break;
			default:cout << "Error!Invalid Input!" << endl;
			}
			cout << "Do you want to use playlist?(Y/N)";
			cin >> yn;
		} while (yn == 'Y' || yn == 'y');
	};
	void createPlaylist() {
		string pName;
		char yn;
		bool duplicate = false;
		//Checking Song Collection
		if (n == NULL) {
			cout << "Song Collection is empty, please create song first!" << endl;
		}
		else {
			playlist2* n0 = new playlist2; //new node for storing the playlist name
			cout << "----------Create Playlist----------" << endl;
			cout << "Enter Playlist name:";
			cin >> pName;
			//Checking Playlist name duplicate
			if (p != NULL) {
				for (int i = 0; i < p; i++) {
					if (head[i]->pName == pName) {
						duplicate = true;
						break;
					}
				}
			}
			//Checking is the first playlist or playlist is not duplicated
			if (p == NULL || duplicate == false) {
				string sName;
				head[p] = n0;
				head[p]->pName = pName;
				head[p]->next = NULL;
				do {
					playlist2* n1 = new playlist2; //new nide for storing the song name
					playlist2* n2; //node for checking the previous song of new song
					bool found = false;
					sc.displaySongs();
					cout << "=================================" << endl;
					cout << "Enter song name:"; cin >> sName;
					playlist2* current = head[p]; //node for checking the duplicate song naame
					//Checkng the song name is stored in song collection
					if (current != NULL) {
						for (int i = 0; i < n; i++) {
							if (title[i] == sName) {
								found = true;
								break;
							}
						}
						//Check and Store song name to playlist
						if (found == true)
						{
							//Checking the song name is stored in playlist before
							while (current != NULL) {
								if (current->pName == sName) {
									duplicate = true;
									break;
								}
								current = current->next;
							}
							//Store song name into playlist
							if (duplicate == false)
							{
								n1->pName = sName;
								n2 = head[p];
								while (n2->next != NULL) {
									n2 = n2->next;
								}
								n2->next = n1;
								n1->next = NULL;
							}
							else {
								cout << "The song name is store in " << head[p]->pName << " already." << endl;
							}
						}
						else {
							cout << "The song name cant be found in song list!" << endl;
						}
					}
					else {
						cout << "The playlist name can not found." << endl;
					}
					found = false;
					duplicate = false;
					cout << "Y to add song continuelly.....";
					cin >> yn;
				} while (yn == 'y');
				//Testing the playlist can store song or no.
				/* playlist2 n3;
				for (int i = 0; i <= p; i++) {
					for (n3 = current[i]; n3 != NULL; n3 = n3->next) {
						cout << n3->pName;
					}
				}
				cout << "2"; */
					p += 1;
			}
			if (duplicate == true) {
				cout << "The playlist name is  duplicated!" << endl;
			}
		}
	};
	void viewPlaylist() {
		playlist2* current;
		int num = 0, id = 1;
		if (p != NULL) {
			cout << "----------Playlist----------" << endl;
			for (int i = 0; i < p; i++) {
				cout << id << ". " << head[i]->pName << " - ";
				for (current = head[i]->next; current != NULL; current = current->next) {
					cout << current->pName;
					if (current->next != NULL) {
						cout << ", ";
					}
				}
				cout << endl;
				id += 1;
			}
		}
		else
		{
			cout << "The list is empty!" << endl;
		}
	};
	void addSongs() {
		string pName;
		char yn;
		bool found = false;
		int id;
		if (p == NULL) {
			cout << "Playlist is empty, please create playlist first!" << endl;
		}
		else {
			viewPlaylist();
			cout << "----------Add Song----------" << endl;
			cout << "Enter Playlist name:";
			cin >> pName;
			if (p != NULL) {
				for (int i = 0; i < p; i++) {
					if (head[i]->pName == pName) {
						found = true;
						id = i;
						break;
					}
				}
			}
			if (found == true) {
				do {
					bool foundName = false;
					string sName;
					playlist2* n1 = new playlist2; //new node for storing song name 
					playlist2* n2; //node for identify the previous song of new song
					bool duplicate = false;
					sc.displaySongs();
					cout << "=================================" << endl;
					cout << "Enter song name:"; cin >> sName;
					playlist2* current = head[id]; // node for checking the duplicated song name
					if (current != NULL) {
						for (int i = 0; i < n; i++) {
							if (title[i] == sName) {
								foundName = true;
								break;
							}
						}
						if (foundName == true)
						{
							while (current != NULL) {
								if (current->pName == sName) {
									duplicate = true;
									break;
								}
								current = current->next;
							}
							if (duplicate == false)
							{
								n1->pName = sName;
								n2 = head[id];
								while (n2->next != NULL) {
									n2 = n2->next;
								}
								n2->next = n1;
								n1->next = NULL;
							}
							else {
								cout << "The song name is store in " << head[id]->pName << " already." << endl;
							}
						}
						else {
							cout << "The song name cant be found in song list!" << endl;
						}
					}
					else {
						cout << "The playlist name can not found." << endl;
					}
					found = false;
					duplicate = false;
					cout << "Y to add song continuelly.....";
					cin >> yn;
				} while (yn == 'y');
			}
			else {
				cout << "The playlist name cannot found." << endl;
			}
		}

	};
	void viewSongs() {
		if (p != NULL) {
			int id;
			playlist2* current;
			for (int i = 0; i < p; i++) {
				cout << i + 1 << ". " << head[i]->pName << "\t";
			}
			cout << "\n----------View Song----------" << endl;
			cout << "Enter song id (1 to " << p << "):"; cin >> id;
			id = id - 1;
			current = head[id]->next;
			cout << head[id]->pName << " - ";
			while (current != NULL) {
				cout << current->pName;
				if (current->next != NULL) {
					cout << ", ";
				}
				current = current->next;
			}
		}
		else { cout << "The list is empty! Pls create the playlist first." << endl; }


	};
	void removeSongs() {
		string pName, sName;
		int d; //number of the playlist
		bool found = false;
		char yn;
		//Checking the playlist exit
		if (p != NULL) {
			viewPlaylist();
			cout << "----------Remove Songs----------" << endl;
			cout << "Enter playlist name:"; cin >> pName;
			//Find the pNmae within the playlist
			for (int i = 0; i < p; i++) {
				if (head[i]->pName == pName) {
					found = true;
					d = i;
					break;
				}
			}
			//Ask song name need to delete if the playlist can found in list
			if (found == true) {
				found = false;
				do {
					playlist2* current = head[d]->next; //node for display all song in the particular playlist
					cout << head[d]->pName << " - ";//display playlist name
					//Display song list
					while (current != NULL) {
						cout << current->pName;
						if (current->next != NULL) {
							cout << ", ";
						}
						current = current->next;
					}
					cout << "Enter song name need to be deleted:"; cin >> sName;
					playlist2* todelete = head[d]->next; //to store the node need to delete
					playlist2* prev = head[d]; //to store the previous node of deleted node
					//To find the song name in the playlist
					while (todelete != NULL) {
						if (todelete->pName == sName) {
							found = true;
							break;
						}
						prev = todelete;
						todelete = todelete->next;
					}
					//Song name exist and start deleting song name
					if (found == true) {
						prev->next = todelete->next;
						delete todelete;
						cout << sName << " is deleted!" << endl;
					}
					else { cout << "The song name doest exist in playlist" << endl; }
					cout << "Y to delete another song in " << pName << "........";
					cin >> yn;
				} while (yn == 'Y' || yn == 'y');
			}
			else {
				cout << "The playlist name cannot found!" << endl;
			}

		}
		else {
			cout << "The list is empty. Pls create playlist first.";
		}


	};
	void playlistNavigation() {};
	void deletePlaylist() {};
};
int main() {
	int option;
	char yn;
	song_collection sc;
	playlist p;
	do {
		cout << "----------Song----------" << endl;
		cout << "1. Song Collection\n2. Playlist" << endl;
		cout << "Select one option:";
		cin >> option;
		switch (option) {
		case 1:sc.selection(); break;
		case 2:p.selection(); break;
		}
		cout << "Do you want to continue?(Y/N):";
		cin >> yn;
	} while (yn == 'Y' || yn == 'y');
};