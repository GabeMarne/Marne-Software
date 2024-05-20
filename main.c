#include <stdio.h>
#include <stdlib.h>

int main() {
	system("clear");
	char *logo[1024] = {
		"MMMM    MMMM   MMMM  M MMM M MMM   MMM",
		"MMMM    MMMM  M    M MM    MM   M M___M",
		"MM MM  MM MM  M    M M     M    M M	",
		"MM  MMMM  MM   MMMMM M     M    M  MMMM",
		"MM   MM   MM",
		"MM   MM   MM",
		"MM   MM   MM  ", 
		"MM   MM   MM",
		"MM        MM",
		"",
		"SSSSSSSSSSSS   SSSS   SSS SSSSS S S S  SSSS  S SSS  SSS",
		"SSSSSSSSSSSS  S S__S S      S   S S S S    S SS    S___S",
		"SS            S    S SSS    S   S S S S    S S     S   ",
		"SSSSSSSSSSSS   SSSS  S      S   SSSSS  SSSSS S      SSSS",
		"SSSSSSSSSSSS",
		"          SS",
		"          SS",
		"SSSSSSSSSSSS",
		"SSSSSSSSSSSS",
	};
	for (int i = 0; i < 19; i++) {
		printf("\n%s", logo[i]);
	}
	printf("\n");
	printf("\nWelcome to Marne Software. Here you can search and install packages from the your main distro repository, from the flathub repository with flatpaks, or from the homebrew with brew package manager.\n");
	printf("\n");
	while (1) {
	char *options[100] = {
		"1. Search packages",
		"2. Install packages",
		"3. Show installed packages",
		"4. Update repositories",
		"5. Install update",
		"6. Unistall package",
		"7. Exit",
	};

	for (int i = 0; i < 7; i++) {
		printf("\n%s\n", options[i]);
	}
	int choice;
	printf("\nSelect an option: ");
	scanf("%d", &choice);

	if (choice == 1) {
		char cmd[70] = "apt search %s";
		char fcmd[70] = "flatpak search %s";
		char bcmd[70] = "brew search %s";
		char pkg[50];
		char completecmd[128];
		char fcompletecmd[128];
		char bcompletecmd[128];
		printf("\nPackage name: ");
		scanf("%s", pkg);
		sprintf(completecmd, cmd, pkg);
		sprintf(fcompletecmd, fcmd, pkg);
		sprintf(bcompletecmd, bcmd, pkg);
		printf("\nMain Repository Packages:\n");
		system(completecmd);
		printf("\nFlathub Repository Packages:\n");
		system(fcompletecmd);
		printf("\nHomebrew Repository Packages:\n");
		system(bcompletecmd);

	} else if (choice == 2) {
		char cmd[70] = "sudo apt install %s";
		char pkg[50];
		char completecmd[128];
		char fcmd[70] = "flatpak install %s";
		char fpkg[170];
		char fcompletecmd[240];
		char bcmd[70] = "brew install %s";
		char bpkg[50];
		char bcompletecmd[128];
		int choic;
		printf("\n1. Install with package manager\n");
		printf("\n2. Install with flatpak\n");
		printf("\n3. Install with brew\n");
		printf("\nSelect option: ");
		scanf("%d", &choic);
		if (choic == 1) {
			printf("\nPackage name: ");
			scanf("%s", pkg);
			sprintf(completecmd, cmd, pkg);
			system(completecmd);
		} else if (choic == 2) {
			printf("\nPackage name: ");
			scanf("%s", fpkg);
			sprintf(fcompletecmd, fcmd, fpkg);
			system(fcompletecmd);
		} else if (choic == 3) {
			printf("\nPackage name: ");
			scanf("%s", bpkg);
			sprintf(bcompletecmd, bcmd, bpkg);
			system(bcompletecmd);
		} else {
			printf("\nInvalid option\n");
		}

	} else if (choice == 3) {
		printf("\n");
		printf("Main packages:\n");
		system("dpkg-query -W -f='${package}\n' | grep -v 'lib'");
		printf("\n");
		printf("Flatpak packages>\n");
		system("flatpak list");
		printf("\n");

	} else if (choice == 4) {
		printf("\nUpdating main repository\n");
		system("sudo apt update");
		printf("\nUpdating flathub\n");
		system("flatpak update");

	} else if (choice == 5) {
		printf("\nInstalling main repository update\n");
		system("sudo apt upgrade");
		
	} else if (choice == 6) {
		char cmd[70] = "sudo apt remove %s";
		char pkg[50];
		char completecmd[128];
		char fcmd[70] = "flatpak remove %s";
		char fpkg[170];
		char fcompletecmd[240];
		char bcmd[70] = "brew uninstall %s";
		char bpkg[50];
		char bcompletecmd[128];
		int choic;
		printf("\n1. Remove main repository package\n");
		printf("\n2. Remove flatpak package\n");
		printf("\n3. Remove brew package\n");
		printf("\nSelect an option: ");
		scanf("%d", &choic);
		if (choic == 1) {
			printf("\nPackage name: ");
			scanf("%s", pkg);
			sprintf(completecmd, cmd, pkg);
			system(completecmd);
		} else if (choic == 2) {
			printf("\nPackage name: ");
			scanf("%s", fpkg);
			sprintf(fcompletecmd, fcmd, fpkg);
			system(fcompletecmd);
		} else if (choic == 3) {
			printf("\nPackage name: ");
			scanf("%s", bpkg);
			sprintf(bcompletecmd, bcmd, bpkg);
			system(bcompletecmd);
		} else {
			printf("\nInvalid option\n");
		}
	}

	else if (choice == 7) {
		system("clear");
		return 0;

	} else {
		printf("\nInvalid option\n");
	}
	}

	return 0;
}
