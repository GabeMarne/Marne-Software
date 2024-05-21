#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void updaterepo() {
	printf("\nUpdating Main Repository\n");
	system("sudo apt update && sudo apt upgrade");
	printf("\nUpdating Flathub Repository:\n");
	system("flatpak update");
	printf("\nUpdating HomeBrew Repository:\n");
	system("brew update");
	printf("\nUpdate Finished\n");
}

void listpackages() {
	printf("\nMain Packages:\n");
	system("dpkg-query -W -f='${package}\n' | grep -v 'lib'");
	printf("\nFlatpak Packages:\n");
	system("flatpak list");
	printf("\nBrew Packages:\n");
	system("brew list");
	printf("\nFinished\n");

}

void searchpackage() {
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
	printf("\nFinished\n");
}

void installpackage() {
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
}

void removepackage() {
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
	printf("\n1. Remove Main Repository Package\n");
	printf("\n2. Remove Flatpak Package\n");
	printf("\n3. Remove Brew Package\n");
	printf("\nSelect an Option: ");
	scanf("%d", &choic);
	if (choic == 1) {
		printf("\nPackage Name: ");
		scanf("%s", pkg);
		sprintf(completecmd, cmd, pkg);
		system(completecmd);
	} else if (choic == 2) {
		printf("\nPackage Name: ");
		scanf("%s", fpkg);
		sprintf(fcompletecmd, fcmd, fpkg);
		system(fcompletecmd);
	} else if (choic == 3) {
		printf("\nPackage Name: ");
		scanf("%s", bpkg);
		sprintf(bcompletecmd, bcmd, bpkg);
		system(bcompletecmd);
	} else {
		printf("\nInvalid Option\n");
	}
}

int main(void) {
	system("clear");
	char *logo[1024] = {
		"MMMM    MMMM  MMMM  M MM M MM   MMM   MMMMMMMMMMMM   MMMM   MM MMMMM M M M  MMMM  M MM  MMM",
		"MMMMM  MMMMM _____M MM   MM  M M___M  MMMMMMMMMMMM  M M__M M     M   M M M _____M MM   M___M",
		"MMMMMMMMMMMM M    M M    M   M M      MM            M      MMM   M   M M M M    M M    M",
		"MMM  MM  MMM  MMMM  M    M   M  MMMM  MMMMMMMMMMMM   MMMMM M     M   MMMMM  MMMM  M     MMMM",
		"MMM  MM  MMM                                    MM  ",
		"MMM  MM  MMM                          MMMMMMMMMMMM  ",
		"MMM  MM  MMM                          MMMMMMMMMMMM  ",
	};

	for (int i = 0; i < 7; i++) {
		printf("%s\n", logo[i]);
		sleep(1);
	}

	char *options[128] = {
		"1. Update Repositories",
		"2. List Installed Packages",
		"3. Search Package",
		"4. Install Package",
		"5. Remove Package",
		"6. Exit",
	};

	while (1) {
		for (int i = 0; i < 6; i++) {
			printf("\n%s\n", options[i]);
		}
		int choice;
		printf("\nSelect an Option: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				updaterepo();
				break;
			case 2:
				listpackages();
				break;
			case 3:
				searchpackage();
				break;
			case 4:
				installpackage();
				break;
			case 5:
				removepackage();
				break;
			case 6:
				system("clear");
				return 0;
		}
	}
}
