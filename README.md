[![Build](https://github.com/jpfleury/guid/actions/workflows/build.yml/badge.svg)](https://github.com/jpfleury/guid/actions)

## About

**guid** (short for *graphical user interface dialogs*) is a C++ tool that lets you create **cross-platform graphical dialogs** directly from the command line, usable from Bash, Python, or any scripting language.

**guid** was built to push the boundaries of what's possible with GUI scripting tools. It lets you build complete, interactive user interfaces (not just dialogs) with dynamic content, layout control, and logical flow.

**Design powerful forms, lists, menus, tabs, and custom layouts, with live updates, persistent windows, command execution, file monitoring, and more. All from your terminal. Compatible with Linux, macOS, and Windows.**

From script to full UI, here's a glimpse of what **guid** can create with minimal effort:

![Demo of guid](doc/demo.gif)

## Key features overview

### Form inputs and controls

- Text entries (plain, password, float, integer)
- Checkboxes and radio buttons
- Combo boxes (static, editable, or populated from file)
- Lists with multiple columns, editable or read-only
- Sliders, spin boxes, and double spin boxes
- File and directory selectors
- Calendar and date pickers
- Color and font selectors
- Custom text areas with live content from file or URL (HTML or plain text)
- Static text blocks with formatting (bold, italics, small-caps, color, size...)
- QR codes
- Standard dialogs: info, warning, error, question
- Progress bars
- Notification icons that respond to stdin

### Layout and structure

- Menus (multi-level, with command execution and return codes)
- Groups (fieldsets), headers, tabs, and multi-column layouts
- Horizontal and vertical spacers, alignment control
- Horizontal rules

### Output and scripting integration

- Flexible console output (variable names, separators, prefixes, base64, etc.)
- Live replacement of markers using file or INI-style variables
- File monitoring for dynamic updates
- Execute shell commands on submit with control over dialog behavior
- Footer logs from file content or command output
- Comment-only arguments for structuring long command lines

### Window behavior and system integration

- Custom window title, size, icon, modal behavior, and taskbar visibility
- Attach dialogs to a parent window or keep them always on top
- Optional minimize/maximize window buttons
- System tray integration: icon, close-to-tray behavior, and tray menu support
- Timeout handling, cancel button visibility

## Install

You can browse static builds ready for Linux, macOS and Windows on the [*Releases* page](https://github.com/jpfleury/guid/releases).

To build **guid** on Linux:

```bash
git clone git@github.com:jpfleury/guid.git
cd guid
sudo apt-get install qtbase5-dev libqt5x11extras5-dev

# Build using CMake
./build.sh -b cmake

# Build using qmake
./build.sh -b qmake

./guid --help
```

## Getting started

We'll progressively build dialogs, from simple prompts to more advanced interfaces, to illustrate some typical use cases.

### Start simple: ask for the user's name

```bash
./guid --entry \
	--title="Welcome aboard" \
	--text="What is your name?" \
	--entry-text="Default name" \
	--ok-label="Continue"
```

### Collect basic user info

```bash
# Refer to https://doc.qt.io/qt-6/qdate.html#toString for the date format.
./guid --forms \
	--title="Basic profile" \
	--add-text="Welcome to your personal setup!" \
		--bold --italics --font-size=13 \
		--foreground-color="#002B5C" --background-color="#F0F8FF" \
	--add-entry="Full name" --var="name" \
	--add-calendar="Date of birth" --forms-date-format="yyyy-MM-dd" --var="birth" \
	--add-double-spin-box="Height" \
		--value=1.72 --decimals=2 --suffix="m" --var="height" \
	--add-double-spin-box="Weight" \
		--value=70.5 --decimals=1 --suffix="kg" --var="weight" \
	--add-entry="Age" --int=30 --var="age" \
	--add-combo="Skill level" \
		--combo-values="Beginner|Intermediate|Expert" --editable --var="skill" \
	--ok-label="Submit info"
```

### Build a multi-section layout with header, groups, and columns

```bash
./guid --forms \
	--title="Enhanced Account Setup" --window-icon=":/info" --width=500 \
	\
	--header="backgroundColor=#ECEFF1@hideLabel=true" \
		--add-text="image=:/info@Welcome to Account Setup!" \
			--tooltip="Please fill in the details below to create your account." \
			--font-size=14 --bold --align=center \
	--header="stop=true" \
	\
	--group="hideLabel=true@Profile Information" \
		--add-entry="Full Name:" --var="fullname" \
		--add-entry="Public Nickname:" --var="nickname" \
		--add-entry="Email Address:" --var="email" \
		--add-file-selection="buttonText=Browse...@Select Profile Picture:" --var="picture" \
	--group="stop=true" \
	\
	--group="hideLabel=true@Preferences" \
		--add-combo="Interface Theme:" --combo-values="defaultIndex=2@Light|Dark|System Default" --var="theme" \
		--add-checkbox="Receive email notification after account setup" --checked --var="email_notif" \
	--group="stop=true" \
	\
	--col1 --add-password="Password:" --var="password" --field-width=240 \
	--col2 --add-password="Confirm Password:" --var="confirm_password" \
	--ok-label="Create Account" --cancel-label="Exit" \
	--separator=$'\n' --output-prefix-ok=$'[ACCOUNT]\n' --output-prefix-err=$'[ACCOUNT-ERROR]\n'
```

### Organize the form with tabs, groups and live file lists

```bash
# Creating a sample file to show file monitoring in guid
plugins_file=guid_demo_active_plugins.txt
plugins=("Plugin A|1.0" "Plugin B|2.3" "Plugin C|1.5" "Plugin D|2.8.1" "Plugin E|3.20.12")
i=0
while ((i < 10)); do \
	printf '%s\n' "${plugins[@]}" | shuf | tr $'\n' '|' > "$plugins_file"; \
	((i++)); \
	sleep 1; \
done &

# Running guid
./guid --forms \
	--title="App Configuration Panel" --window-icon=":/app-icon" --width=500 \
	\
	--tab="General" \
		--header="backgroundColor=#EEEEEE@hideLabel=true" \
			--add-text="General Preferences" --bold --font-size=13 \
		--header="stop=true" \
		--add-combo="Interface language" \
			--combo-values="defaultIndex=1@English|Español|Français" --var="lang" \
		--add-checkbox="Enable notifications" --checked --var="notify" \
	\
	--tab="selected=true@Editor" \
		--group="Font & Tabs" \
			--add-entry="Editor font string (e.g., Monospace 10)" --var="font" \
			--add-text="(Use '--font-selection' for help)" --italics --font-size=10 \
			--add-spin-box="Tab size" --min-value=2 --max-value=8 --value=4 --var="tabsize" \
		--group="stop=true" \
		--add-text="Active Editor Plugins (live refresh)" --font-size=13 --bold --align=center \
		--add-vspacer="15" \
		--add-list="excludeFromOutput=true@hideLabel=true" \
			--column-values="Plugin Name|Version" --show-header \
			--list-values-from-file="monitor=true@sep=|@$plugins_file" \
	\
	--tab="stop=true" \
	--ok-label="Apply" --no-cancel
```

### Integrate dynamic data and run post-submit actions

```bash
# Can be dynamically populated files
cities_file=guid_demo_cities.txt
user_file=guid_demo_user.ini
echo $'Montréal\nParis\nTokyo' > "$cities_file"
echo $'auth=Connected\nstatus=Writing post...' > "$user_file"

# Running guid
./guid --forms \
	--title="Profile Completion" --width=550 \
	--header="backgroundColor=#157db9@foregroundColor=#ffffff@hideLabel=true" \
		--add-text="monitorMarkerFile1=$user_file@monitorMarkerFile2=$user_file@monitorVarName1=auth@monitorVarName2=status@Live Status: GUID_MARKER_1 (GUID_MARKER_2)" \
			--font-size=13 --bold \
	--header="stop=true" \
	--add-combo="Choose a city" \
		--combo-values-from-file="monitor=true@$cities_file" \
		--editable --var="city" \
	--add-entry="Email" --var="email" \
	--add-entry="Phone number" --var="phone" \
	--action-after-ok-click="keepOpen=true@valuesToFooter=true@command=echo<>GUID_VALUES" \
	--footer-name="Latest submissions" --footer-entries=4
```

### Edit or display external documents and web content

**Editable file-based notes:**

```bash
# Sample file
notes_file=guid_demo_notes.txt
for i in {1..10}; do echo $'Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n' >> "$notes_file"; done

# Running guid
user_values=$(./guid --forms \
	--title="Edit Notes" --font="Monospace, 12pt" --width=600 \
	--comment="First field: editable text information" \
	--add-text-info="Text notes" --filename="$notes_file" --editable \
	--comment="Second field: checkbox" \
	--add-checkbox="I have reviewed my edits" \
	--comment="Custom separator (form feed) used to split the fields in the output" \
	--separator=$'\f' \
	--ok-label="Save")

# Getting the second field value
[[ ${user_values##*$'\f'} == true ]] && echo "The user has reviewed the notes." || echo "The user has not reviewed the notes."
```

**Display web HTML content:**

```bash
./guid --forms \
	--title="Online Documentation" --width=500 --height=500 \
	--add-text-browser="hideLabel=true" --url="https://example.org/user-guide"
```

### Ask questions, inform users, and show progress

**Confirmation prompt:**

```bash
./guid --question \
	--title="Enable Advanced Mode?" \
	--text="Do you want to activate advanced settings?<br>A restart may be required." \
	--ok-label="Enable Now" --cancel-label="Later"
```

**Warning dialog:**

```bash
./guid --warning \
	--title="Action Required" \
	--text="This change cannot be undone.<br>Proceed with caution."
```

**Error alert:**

```bash
./guid --error \
	--title="Connection Error" \
	--text="Unable to reach the server.<br>Please check your network connection."
```

**Progress indicator (pulsating):**

```bash
./guid --progress \
	--title="Processing" \
	--text="Installing components..." \
	--pulsate --auto-close --timeout=5
```

**Progress updates via stdin:**

```bash
for i in {1..100}; do \
	echo "$i"; \
	sleep 0.05; \
done | \
guid --progress \
	--title="Processing" \
	--text="Installing components..." \
	--auto-close
```

**Color selection:**

```bash
./guid --color-selection \
	--title="Pick a Color" \
	--color="#0000ff"
fi
```

### Interactive control panel in the system tray

```bash
# Sample file
manual_file=guid_demo_manual_file.txt
echo "Lorem ipsum dolor sit amet." > "$manual_file"

# Running guid
./guid --forms \
	--title="Control Panel" --width=600 \
	--win-min-button --win-max-button --always-on-top \
	--systray-icon=":/info" --close-to-systray \
	--add-menu="File#Open Manual;-1;xdg-open<>$manual_file|Exit;1" \
	--header="backgroundColor=#DDDDDD@hideLabel=true" \
		--add-text="System Control Center" --font-size=14 --bold --align=center \
	--header="stop=true" \
	--add-scale="CPU Throttle" --min-value=0 --max-value=100 --step=5 --value=80 --var="cpu_throttle" \
	 --add-scale="RAM Limit (GB)" --min-value=1 --max-value=10 --step=1 --value=3 --var="ram_limit" \
	--add-qr-code="size=150@https://example.com/dashboard" --align=center \
	--action-after-ok-click="keepOpen=true@valuesToFooter=true@command=echo<>GUID_VALUES" \
	--footer-name="Latest settings" --footer-entries=5
```

## guid documentation

The file [help-all.md](doc/help-all.md) contains the complete and verbose output of the `guid --help-all` command.

## License

Copyright (C) 2021-2025  Jean-Philippe Fleury <https://github.com/jpfleury>  
Copyright (C) 2014  Thomas Lübking <thomas.luebking@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License version 2.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

## Third-party code

- **guid** was forked from [qarma](https://github.com/luebking/qarma) in 2021 and has since evolved independently.

- **guid** includes the [QR Code generator library](https://github.com/nayuki/QR-Code-generator/tree/master/cpp), developed by the Nayuki project and released under the MIT license.
