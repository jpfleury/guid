## guid help

Below is the complete output of the `guid --help-all` command.

### Help options

```
-h, --help
	Show help options
--help-all
	Show all help options
--help-general
	Show general options
--help-misc
	Show miscellaneous options
---------------------------------------------
--help-calendar
	Show calendar options
--help-color-selection
	Show color selection options
--help-entry
	Show text entry options
--help-error
	Show error dialog options
--help-file-selection
	Show file selection options
--help-forms
	Show forms dialog options
--help-info
	Show info dialog options
--help-list
	Show list options
--help-notification
	Show notification icon options
--help-password
	Show password dialog options
--help-progress
	Show progress options
--help-question
	Show question options
--help-scale
	Show scale options
--help-text-info
	Show text information options
--help-warning
	Show warning dialog options
```

### Miscellaneous options

```
--about
	About guid
--short-version
	Print plain version number only
--version
	Print version with program name
```

### General options

```
--title=TITLE
	Set the dialog title
--window-icon=/path/to/icon
	Set the window icon
--width=WIDTH
	Set the dialog width
--height=HEIGHT
	Set the dialog height
---------------------------------------------
--ok-label=TEXT
	Set the label of the Ok button
--cancel-label=TEXT
	Set the label of the Cancel button
---------------------------------------------
--timeout=TIMEOUT
	Set dialog timeout in seconds
--always-on-top
	Force the dialog to be always on top of other windows
--no-taskbar
	Don't display the dialog in the taskbar
--attach=WINDOW
	Set the parent window to attach to
--modal
	Set the modal hint
--output-prefix-ok=PREFIX
	Set prefix for output sent to stdout
--output-prefix-err=PREFIX
	Set prefix for output sent to stderr
```

### Application options

```
--display=DISPLAY
	X display to use
---------------------------------------------
--calendar
	Display calendar dialog
--color-selection
	Display color selection dialog
--entry
	Display text entry dialog
--error
	Display error dialog
--file-selection
	Display file selection dialog
--font-selection
	Display font selection dialog
--forms
	Display forms dialog
--info
	Display info dialog
--list
	Display list dialog
--notification
	Display notification
--password
	Display password dialog
--progress
	Display progress indication dialog
--question
	Display question dialog
--scale
	Display scale dialog
--text-info
	Display text information dialog
--warning
	Display warning dialog
```

### Calendar options

```
--text=TEXT
	Set the dialog text
--align=left|center|right
	Set text alignment
---------------------------------------------
--day=DAY
	Set the calendar day
--month=MONTH
	Set the calendar month
--year=YEAR
	Set the calendar year
--date-format=PATTERN
	Set the format for the returned date
---------------------------------------------
--timeout=TIMEOUT
	Set dialog timeout in seconds
```

### Color selection options

```
--color=VALUE
	Set the color
--custom-palette=/path/to/file.gpl
	Load a custom GPL file for standard colors
--show-palette
	Show the palette
```

### Text entry options

```
--text=TEXT
	Set the dialog text
---------------------------------------------
--entry-text=TEXT
	Set the entry text
--hide-text
	Hide the entry text
---------------------------------------------
--float=FLOATING_POINT
	Floating point input only, preset given value
--int=INTEGER
	Integer input only, preset given value
--values=v1|v2|v3|...
	Offer preset values to pick from
```

### Error options

```
--text=TEXT
	Set the dialog text
--ellipsize
	Do wrap text (zenity has a rather special problem here)
--no-markup
	Do not enable HTML markup
--no-wrap
	Do not enable text wrapping
---------------------------------------------
--icon-name=ICON_NAME
	Set the dialog icon
---------------------------------------------
--selectable-labels
	Allow to select text for copy and paste
```

### File selection options

```
--filename=/path/to/file
	Set the file selected by default
--file-filter=NAME|PATTERN1 PATTERN2...
	Set a filename filter
--directory
	Activate directory-only selection
--multiple
	Allow multiple files to be selected
---------------------------------------------
--confirm-overwrite
	Confirm file selection if the file selected already exists
--save
	Activate save mode
---------------------------------------------
--separator=SEPARATOR
	Set output separator character
```

### Font selection options

```
--sample=TEXT
	Sample text (default is "The quick brown fox jumps over the lazy dog."
--pattern=%1-%2:%3:%4
	Output pattern where %1 is name, %2 is size, %3 is weight, %4 is slant.
--type=[vector][,bitmap][,fixed][,variable]
	Filter fonts (default is all)
```

### Forms dialog options

```
Widgets are added to forms dialog using the following syntax:
	--add-WIDGET-TYPE="Label displayed"
Example:
	guid --forms \
		--add-entry="Your name" \
		--add-file-selection="Your document"
Several widgets can be configured with variables using a syntax like this:
	--add-WIDGET-TYPE="variableName=Value@anotherVariableName=Value@Label displayed"
Example:
	guid --forms \
		--add-text="image=:/info@Text with image" \
		--add-entry="Your name" \
		--add-file-selection="buttonText=Select file@Your document"
The list of variables supported is displayed at the beginning of each widget section.
	
---------------------------------------------
--text="Form label (form description)"
	Set the form label (always displayed on top, and bold by default
--align=left|center|right
	Set label alignment
--no-bold
	Remove bold for the form label
--italics
	Set form label in italics
--underline
	Set form label format to underline
--small-caps
	Set form label rendering to small-caps type
--font-family=FAMILY
	Set font family for the form label
--font-size=SIZE
	Set font size for the form label
--foreground-color=COLOR
	Set form label color. Example:
		guid --forms \
			--text="Form label (form description)" \
				--foreground-color="#0000FF" \
			--add-entry="Entry field not colored"
--background-color=COLOR
	"Set form label background color. Example:
		guid --forms \
			--text="Form label (form description)" \
			--background-color="#0000FF" \
			--add-entry="Entry field not colored"
---------------------------------------------
--header="[backgroundColor=COLOR@][foregroundColor=COLOR@][hideLabel=true@]
		[stop=true@]Header label"
	"Add a header to the form.
	The header is a section without margins (so the background color fills the entire
	dialog width) under the top menu but over form fields. It's useful to display
	information (input fields added in the header are not parsed for user input). Next
	fields will be added to the header unless a new "--header" is added containing the
	variable "stop=true". Example:
		guid --forms \
			--header="backgroundColor=#DEDEDE@hideLabel=true" \
				--add-text="image=:/info@Text added in the header" \
				--add-text="More text in the header" --bold --align=center \
			--header="stop=true" \
			--add-entry="Field outside the header"
---------------------------------------------
--group="[addLabel=Group label@][stop=true@]Group name"
	Add a group box (fieldset).
	Next fields will be added to the group unless a new "--group" is added containing
	the variable "stop=true". Example:
		guid --forms \
			--text="Form with a group box (fieldset)" \
			--group="Group name" \
				--add-entry="Text field in the group" \
				--add-entry="Another text field in the group" \
			--group="stop=true" \
			--add-text="Text outside the group"
---------------------------------------------
--tab="[addLabel=Tab bar label@][disableButtons=true@][selected=true@]
	[stop=true@][verboseTabBar=true@]Tab name"
	Create a tab bar.
	After adding "--tab=NAME", next fields will be added to the tab NAME unless another
	one is specified with "--tab=ANOTHER_NAME". Mark the tab as selected by default when
	the dialog is shown with the variable "selected=true". Stop adding fields in the last
	tab with the variable "stop=true". Example:
		guid --forms \
			--text="Form with a tab bar" \
			--tab="Tab 1" \
				--add-entry="Text field in the tab 1" \
				--add-entry="Another text field in the tab 1" \
			--tab="selected=true@Tab 2" \
				--add-spin-box="Spin box in the tab 2" --min-value=10 --value=50 \
			--tab="stop=true" \
			--add-scale="Field outside the tab bar" --step=5
	To disable dialog buttons when the tab is displayed, add the variable
	"disableButtons=true". Example:
		guid --forms \
			--text="Form with a tab bar" \
			--tab="Tab 1" \
				--add-entry="Text field in the tab 1" \
				--add-entry="Another text field in the tab 1" \
			--tab="disableButtons=true@Tab 2" \
				--add-spin-box="Spin box in the tab 2" --min-value=10 --value=50 \
			--tab="stop=true" \
			--add-scale="Field outside the tab bar" --step=5
	To include information about the tab bar in values printed to the console, add the
	variable "verboseTabBar=true". Separators will be added in the output between tab
	fields and the selected tab will be marked with "*".
---------------------------------------------
--col1
	Start a two-field row.
	The next form field specified will be added in the first column. See "--col2" for
	details.
--col2
	Finish a two-field row.
	The next form field specified will be added in the second column. Example:
		guid --forms --width=500 \
			--text="The next row has two columns:" \
			--col1 \
				--add-entry="Left entry (column 1)" --int=5 \
			--col2 \
				--add-entry="Right entry (column 2)" --field-width=100 \
			--add-entry="Outside columns"
--add-hspacer=before|after
	Add horizontal expanding spacer before or after the current
	column content
--valign=top|center|bottom|baseline
	Set vertical alignment of the current column. Example:
		guid --forms --width=500 \
			--text="The next row has two columns:" \
			--col1 --valign=bottom \
				--add-text="Aligned to the bottom" \
			--col2 \
				--add-text="Lorem<br />ipsum<br />dolor<br />sit<br />amet" \
			--add-entry="Outside columns"
---------------------------------------------
--add-calendar="[hideLabel=true@]Calendar label"
	Add a calendar in forms dialog
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-checkbox="[addLabel=Checkbox label@]Checkbox text"
	Add a checkbox in forms dialog
--checked
	Make the checkbox checked by default
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-combo="[hideLabel=true@]Combo label"
	Add a combo box in forms dialog
--combo-values=[defaultIndex=Index number@]List of values separated by |
	List of values for the combo box.
	To select a specific index by default, add the variable "defaultIndex=Index number".
--combo-values-from-file=[defaultIndex=Index number@][monitor=VALUE@]Path to file
	Use the file content as combo values (one value per line).
	To select a specific index by default, add the variable "defaultIndex=Index number".
	To monitor file changes, add "monitor=true". Example:
		guid --forms \
			--add-combo="Combo label" \
			--combo-values-from-file="defaultIndex=1@monitor=true@C:\\Path\\to\\file.txt"
--editable
	Allow the user to edit combo values
--field-width=WIDTH
	Set the field width
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-entry="[hideLabel=true@]Entry label"
	Add a text entry in forms dialog
--float=FLOATING_POINT
	Floating point input only, preset given value
--int=INTEGER
	Integer input only, preset given value
--field-width=WIDTH
	Set the field width
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-file-selection="[buttonText=Text@][hideLabel=true@]File selection label"
	File selection options.
	The field name is displayed in a button that opens the file selection dialog.
	The selection is added and displayed in a text entry.
--filename=/path/to/file
	Set the file selected by default
--file-filter=NAME|PATTERN1 PATTERN2...
	Set a filename filter
--directory
	Activate directory-only selection
--multiple
	Allow multiple files to be selected
--file-separator=SEPARATOR
	Set output separator character if there are multiple files selected
	(default is "~")
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
---------------------------------------------
--add-list="[addNewRowButton=true@][excludeFromOutput=true@]
			[hideLabel=true@]List label"
	Add a list in forms dialog.
	To include a button allowing to add new rows when clicked, add the variable
	"addNewRowButton=true". Example:
		guid --forms \
			--add-list="addNewRowButton=true@My list" \
				--column-values="C1|C2" --show-header \
				--list-values="v1|v2|v3|v4" --editable
	To exclude the list from the output printed to the console, add the variable
	"excludeFromOutput=true". It's useful when using lists for displaying data instead of
	asking users to make a selection.
	To hide the list label, add the variable "hideLabel=true". Example:
		guid --forms \
			--add-list="addNewRowButton=true@hideLabel=true@Label hidden" \
				--column-values="C1|C2" --show-header \
				--list-values="v1|v2|v3|v4" --editable
--column-values=Column names separated by |
	List of column names
--list-values=List values separated by |
	List values
--list-values-from-file="[addValue=Value@][monitor=true@][sep=Separator@]Path to file"
	Use the file content as list values. Example:
		guid --forms \
			--add-list="List label" \
				--column-values="Column 1|Column 2" --show-header \
				--list-values-from-file="/path/to/file"
	To add automatically a value at the beginning of each row (for example the
	value "false" in combination with "--checklist"), add the variable "addValue=Value".
	For example, to add the word "false", so checkboxes won't be checked by default:
		guid --forms \
			--add-list="List label" --checklist \
				--column-values="Delete|Column 1|Column 2" --show-header \
				--list-values-from-file="addValue=false@/path/to/file"
	To monitor file changes, add the variable "monitor=true". Example:
		guid --forms \
			--add-list="List label" \
				--column-values="Column 1|Column 2" --show-header \
				--list-values-from-file="monitor=true@/path/to/file"
	By default, the character "|" is used as separator between values. To use another
	separator, specify it with the variable "sep=Separator". Example with "," as
	separator:
		guid --forms \
			--add-list="List label" \
				--column-values="Column 1|Column 2" --show-header \
				--list-values-from-file="sep=,@/path/to/file"
	Example with file changes monitored and with a custom separator:
		guid --forms \
			--add-list="List label" \
				--column-values="Column 1|Column 2" --show-header \
				--list-values-from-file="monitor=true@sep=,@/path/to/file"
--checklist
	Add checkboxes in the first column (multiple rows will be selectable)
--radiolist
	Add radio buttons in the first column (only one row will be selectable)
--editable
	Allow the user to edit list values
--read-only-column=Column number
	If editable, set a specific column as read only
--multiple
	Allow multiple rows to be selected
--no-selection
	Prevent row selection (useful to display information in a structured way
	without user interaction)
--print-column=NUMBER|all
	Print a specific column to the console.
	Default is "1" (print only the first column). The value "all" can be used to print
	all columns.
--print-values=selected|all
	Print selected values (by default) or all values (useful in combination
	with "--editable" to get updated values).
--list-row-separator=SEPARATOR
	Set output separator character for list rows (default is "~")
--field-width=WIDTH
	Set the field width
--field-height=HEIGHT
	Set the field height
--show-header
	Show the columns header
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-menu="addLabel=Menu label@Menu settings"
	Add a menu in forms dialog.
	Note that this widget is not a user input field, so it doesn't appear in the console
	(no even as empty value) when user input is printed.
	First level menu items must be separated with the character "|". Example:
		Main Item A|Main Item B|Main Item C
	Second level menu items must be separated with the character "#". Example:
		Main Item A#Subitem A1#Subitem A2|Main Item B|Main Item C#Subitem C1
	A click on a first level menu item will initiate an action if it doesn't contain
	subitems. However, a click on a first level menu item containing subitems will only
	display the second level menu.
	A click on a second level menu item will always initiate an action since they can't
	contain subitems.
	Each menu item without subitems can have up to 5 settings separated with the
	character ";", as follows:
		1              2         3              4                    5
		Menu item name;Exit code;Command to run;Print command output;Icon
	The menu item name is mandatory. Other settings have these default values:
		1              2  3  4 5
		Menu item name;-1;"";0;""
	Allowed values are as follows:
	1) Menu item name: Any string not containing the character ";".
	2) Exit code: Integer. If the value is < 0, the dialog will not be closed after
		a click on the menu item. If the value is >=0 and <= 255, the dialog will be
		closed with the exit code sent by the command "exit()".
	3) Command to run: The executable name or the executable path and its arguments.
		Arguments must be separated with "<>". For example, if the command to run is
		the following:
			explorer.exe /separate, "C:\\Users\\My Name\\Desktop"
		it must be set like this:
			explorer.exe<>/separate,<>"C:\\Users\\My Name\\Desktop"
		It's also possible to specify one of these internal commands:
			guidInfo<>Information to display
			guidWarning<>Warning to display
			guidError<>Error to display
	4) Print command output: true|false. If the value is "true", the command output
		will be printed to the console.
	5) Icon: For now, the only valid value is "false". If the value is "false", the
		default icon won't be added to the left of the menu item.
		TODO: Set arbitrary icon.
	No matter if the dialog is closed or not after a click on the menu item, all
	settings (menu name, exit code, etc.) are printed to the console after a click,
	so it can be parsed by an external script. Here's an example:
		guid --forms \
			--add-menu="File#Profile;-1;explorer.exe<>%UserProfile%;0|Exit;10"
	To add separators between first level menu items, add the variable "sep=SEP".
	Example:
		guid --forms \
			--add-menu="sep=|@File#Profile;-1;explorer.exe<>%UserProfile%;0|Exit;10"
	If a menu is the first widget added to the form and the form doesn't have a main
	label added with --text="Form label (form description)", special settings are
	applied to the menu to have it look like a main application menu. If we want a menu
	on top of the dialog but still have a form label (form description), we can't add
	the form label with --text="Form label", but with --add-text="Form label" after the
	menu. Example:
		guid --forms \
			--add-menu="Item A;10|Item B;20" \
			--add-text="Form label" --bold
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets.
---------------------------------------------
--add-password="[hideLabel=true@]Password label"
	Add a password entry in forms dialog
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-qr-code="[addLabel=QR code label@][size=Size@]QR Code text"
	Add a QR code in forms dialog.
	Note that this widget is not a user input field, so it doesn't appear in the console
	(no even as empty value) when user input is printed.
--align=left|center|right
	Set QR code alignment
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets.
---------------------------------------------
--add-scale="[hideLabel=true@]Scale label"
	Add a scale (slider) in forms dialog
--value=VALUE
	Set initial value
--min-value=VALUE
	Set minimum value
--max-value=VALUE
	Set maximum value
--step=VALUE
	Set step size
--hide-value
	Hide value
--print-partial
	Print the value to the console each time it's changed by the user
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-spin-box="[hideLabel=true@]Spin box label"
	Add a spin box in forms dialog
--value=VALUE
	Set initial value
--min-value=VALUE
	Set minimum value
--max-value=VALUE
	Set maximum value
--prefix=PREFIX
	Set prefix
--suffix=SUFFIX
	Set suffix
--field-width=WIDTH
	Set the field width
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-double-spin-box="[hideLabel=true@]Double spin box label"
	Add a double spin box in forms dialog
--value=VALUE
	Set initial value
--decimals=VALUE
	Set the number of decimals
--min-value=VALUE
	Set minimum value
--max-value=VALUE
	Set maximum value
--prefix=PREFIX
	Set prefix
--suffix=SUFFIX
	Set suffix
--field-width=WIDTH
	Set the field width
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
	so it doesn't appear in the console (no even as empty value) when user input is printed.
--var=NAME
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-text="[addLabel=Text label@][defMarkerVal1=Value@][image=Path to image@]
			[monitorMarkerFile1=Path to file@][monitorVarName1=Variable name@]Text"
	Add text without field.
	Note that this widget is not a user input field, so it doesn't appear in the console
	(no even as empty value) when user input is printed.
	To add an image to the left, add the variable "image=Path to the image". Example:
		guid --forms \
			--add-text="image=/path/to/image.png@Text displayed"
	Default resources shipped with guid can be used. To do so, start the image path
	with ":/" followed by the resource name. For example, to use a "warning" icon:
		guid --forms \
			--add-text="image=:/warning@Text displayed"
	A marker named "GUID_MARKER_1" can be added in the text and it will be replaced by the file
	content specified with the variable "monitorMarkerFile1=Path to file". Up to 9 markers can
	be used (from GUID_MARKER_1 to GUID_MARKER_9). If the file content is empty, a default value
	can be specified with the variable "defMarkerVal1=Value" (and "defMarkerVal2=Value",
	"defMarkerVal3=Value", etc.). Example:
		guid --forms \
			--add-text="defMarkerVal1=?monitorMarkerFile1=/to/file.txt@Lorem GUID_MARKER_1 amet."
	It's possible to monitor only part of the file. To do so, add the variable
	"monitorVarName=Variable name", and only the value of the variable specified will be used
	as content. For example, let's say we have a file "/to/settings.sh" with this content:
		name=Little Mouse
		age=2
		color=grey
	We can replace the marker GUID_MARKER_1 with only the value of the variable "age" like this:
		guid --forms \
			--add-text="monitorMarkerFile1=/to/settings.sh@monitorVarName1=age@Age is GUID_MARKER_1."
--tooltip=Tooltip text
	Set tooltip displayed when the cursor is over
--wrap
	Enable text wrapping
--align=left|center|right
	Set text alignment
--bold
	Set text in bold
--italics
	Set text in italics
--underline
	Set text format to underline
--small-caps
	Set text rendering to small-caps type
--font-family=FAMILY
	Set font family
--font-size=SIZE
	Set font size
--foreground-color=COLOR
	Set text color. Example:
		guid --forms \
			--add-text="Lorem ipsum" --foreground-color="#0000FF"
--background-color=COLOR
	Set text background color. Example:
		guid --forms \
			--add-text="Lorem ipsum" --background-color="#0000FF"
--field-width=WIDTH
	Set the field width
--field-height=HEIGHT
	Set the field height
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets.
---------------------------------------------
--add-hrule="[addLabel=Rule label@]Rule color
	Add a horizontal rule with the color specified. Example:
		guid --forms \
			--add-text="Lorem ipsum" \
			--add-hrule="#B1B1B1" \
			--add-entry="Text field"
	Note that this widget is not a user input field, so it doesn't appear in the console
	(no even as empty value) when user input is printed.
--field-width=WIDTH
	Set the field width
--field-height=HEIGHT
	Set the field height
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets.
---------------------------------------------
--add-vspacer="[addLabel=Vertical spacer label@]Height"
	Add a vertical spacer.
	Note that this widget is not a user input field, so it doesn't appear in the console
	(no even as empty value) when user input is printed.
---------------------------------------------
--add-text-info="[hideLabel=true@]Text info label"
	Add text information.
	Note that this widget is a user input field only when the argument "--editable"
	is used. Otherwise, it's not a user input field, so it doesn't appear in the console
	(no even as empty value) when user input is printed.
--filename="[monitor=true@]Path to file"
	Get content from the specified file
--url=URL
	Get content from the specified URL (curl must be installed on the system)
--curl-path="Path to curl"
	Set path to the curl binary (default is "curl")
--editable
	Allow the user to edit text
--plain
	Force plain text (zenity default limitation), otherwise guid will try
	to guess automatically the format
--html
	Force HTML format, otherwise guid will try to guess automatically the format
--newline-separator=SEPARATOR
	Replace newlines with SEPARATOR in the text printed to the console (so the
	output is only on one line)
--field-width=WIDTH
	Set the field width
--field-height=HEIGHT
	Set the field height
--align=left|center|right
	Set text alignment
--bold
	Set text in bold
--italics
	Set text in italics
--underline
	Set text format to underline
--small-caps
	Set text rendering to small-caps type
--font-family=FAMILY
	Set font family
--font=TEXT
	Set the text font
--font-size=SIZE
	Set font size
--foreground-color=COLOR
	Set text color. Example:
		guid --forms \
			--add-text-info="Text info label" --foreground-color="#0000FF" \
				--filename="/path/to/file.txt"
--background-color=COLOR
	Set text background color. Example:
		guid --forms \
			--add-text-info="Text info label" --background-color="#0000FF" \
				--filaneme="/path/to/file.txt"
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets.
--var=NAME
	Only when the field is editable.
	Variable name added before the field value when printed to the console.
	Spaces are removed and the character "=" is added after the variable name. Example
	without "--var":
		guid --forms \
			--add-calendar="Choose a date" \
			--add-entry="Type your pseudo"
	Here's what the output printed to the console looks like:
		2020-12-12|Little Mouse
	Example with "--var":
		guid --forms \
			--add-calendar="Choose a date" --var="cal" \
			--add-entry="Type your pseudo" --var="pseudo"
	Here's what the output printed to the console looks like:
		cal=2020-12-12|pseudo=Little Mouse
---------------------------------------------
--add-text-browser="[hideLabel=true@]Text browser label"
	Add read-only HTML information with click on links enabled.
	Note that this widget is not a user input field, so it doesn't appear in the console
	(no even as empty value) when user input is printed.
--filename=/path/to/file
	Get content from the specified file
--url=URL
	Get content from the specified URL (curl must be installed on the system)
--curl-path="Path to curl"
	Set path to the curl binary (default is "curl")
--field-width=WIDTH
	Set the field width
--field-height=HEIGHT
	Set the field height
--hide
	Hide the widget but retain its size in the dialog.
	Useful mainly for positioning other widgets.
---------------------------------------------
--win-min-button
	Add a "Minimize" button to the dialog window
--win-max-button
	Add a "Maximize" button to the dialog window
---------------------------------------------
--close-to-systray
	Hide the dialog (instead of exiting) when clicking the window "Close" button.
	The system tray must be enabled with --systray-icon="Path to icon".
--systray-icon="Path to icon"
	Add the icon specified in the system tray.
	Clicking the "Close" window button will minimize the dialog in the systray, and a
	menu will be displayed with a right-click on the systray icon.
---------------------------------------------
--action-after-ok-click="[keepOpen=true@]
						[valuesToFooter=true@][commandToFooter=true@]
						[command=command name[<>command argument][<>another arg]"
	Action after a click on the OK button.
	No matter the options specified, values are always printed to the console. Default is
	to exit. Variables that can be used are the following:
	- Set "keepOpen=true" to keep the forms dialog open (fields will be cleared).
	- Set "valuesToFooter=true" to add values to the dialog footer.
	- Set "commandToFooter=true" to add command output to the dialog footer.
	- Set "command" to run a command with values as input (values will also be printed
		to the console and fields will be cleared). Arguments must be separated with
		"<>". Actual values will be put where the variable/marker "GUID_VALUES" is added.
		If there's no variable/marker, values will be added at the end of the command.
		Example:
			guid --forms \
				--add-entry="Folder" \
				--action-after-ok-click="command=explorer.exe<>/separate,<>GUID_VALUES"
		To convert values to base64, use the variable/marker "GUID_VALUES_BASE64".
		Example:
			action="keepOpen=true"
			action+="@commandToFooter=true"
			action+="@command=myCommand"
			action+="<>myCommandArg1<>myCommandArg2<>GUID_VALUES_BASE64<>myCommandArg3"
			guid --forms \
				--add-entry="Folder" \
				--action-after-ok-click="$action"
		To convert values to base64 in a format suitable for URL, use the variable/marker
		"GUID_VALUES_BASE64_URL".
--no-cancel
	Hide Cancel button
---------------------------------------------
--footer-name="Footer name"
	Name of the footer fieldset
--footer-entries="Number of entries"
	Number of entries to display in the footer (most recent entries are always displayed first).
	Default is 3.
--footer-from-file="[monitor=true@]Path to file"
	Use the file content as a source of footer entries.
	To monitor file changes, add the variable "monitor=true".
---------------------------------------------
--forms-date-format=PATTERN
	Set the format for the returned date
--forms-align=left|center|right
	Set label alignment for the entire form
--separator=SEPARATOR
	Set output separator character
--comment=COMMENT
	Add comment for convenience in the command line arguments.
	It'll be ignored when parsing arguments. Example:
		guid --forms \
			--text="Form with a tab bar" \
			--comment="--------------- TAB 1 ---------------" \
			--tab="Tab 1" \
				--add-entry="Text field in the tab 1" \
				--add-entry="Another text field in the tab 1" \
			--comment="--------------- TAB 2 ---------------" \
			--tab="Tab 2" \
				--add-spin-box="Spin box in the tab 2" --min-value=10 --value=50 \
			--tab="stop=true" \
			--comment="--------------- SCALE ---------------" \
			--add-scale="Field outside the tab bar" --step=5
```

### Info options

```
--text=TEXT
	Set the dialog text
--ellipsize
	Do wrap text (zenity has a rather special problem here)
--no-markup
	Do not enable HTML markup
--no-wrap
	Do not enable text wrapping
---------------------------------------------
--icon-name=ICON_NAME
	Set the dialog icon
---------------------------------------------
--selectable-labels
	Allow to select text for copy and paste
```

### List options

```
--text=TEXT
	Set the dialog text
--align=left|center|right
	Set text alignment
---------------------------------------------
--checklist
	Add checkboxes in the first column (multiple rows will be selectable)
--imagelist
	Use an image in the first column
--radiolist
	Add radio buttons in the first column (only one row will be selectable)
---------------------------------------------
--column="Column name"
	Add a column
--hide-column=NUMBER
	Hide a specific column
--print-column=NUMBER|all
	Print a specific column to the console.
	Default is "1" (print only the first column). The value "all" can be used to print
	all columns.
--hide-header
	Hide the column headers
---------------------------------------------
--list-values-from-file="[monitor=true@][sep=Separator@]Path to file"
	Use the file content as list values.
	To monitor file changes, add the variable "monitor=true". By default, the character
	"|" is used as separator between values. To use another separator, specify it with
	the variable "sep=Separator". Example:
		guid --list \
			--text="List label" \
			--column="Column 1" --column="Column 2" \
			--list-values-from-file="monitor=true@sep=,@/path/to/file"
---------------------------------------------
--editable
	Allow the user to edit list values
--multiple
	Allow multiple rows to be selected
--no-selection
	Prevent row selection (useful to display information in a structured way
	without user interaction)
--print-values=selected|all
	Print selected values (by default) or all values (useful in combination
	with "--editable" to get updated values).
---------------------------------------------
--mid-search
	Change list default search function searching for text in the middle, not at the
	beginning
--field-height=HEIGHT
	Set the field height
--separator=SEPARATOR
	Set output separator character
```

### Notification icon options

```
--text=TEXT
	Set the dialog text
---------------------------------------------
--hint=TEXT
	Set the notification hints
---------------------------------------------
--listen
	Listen for commands on stdin
--selectable-labels
	Allow to select text for copy and paste
```

### Password dialog options

```
--prompt=TEXT
	The prompt for the user (field label)
--username
	Add a username field
--field-width=WIDTH
	Set the field width
```

### Progress options

```
--text=TEXT
	Set the dialog text
---------------------------------------------
--percentage=PERCENTAGE
	Set initial percentage
--pulsate
	Pulsate progress bar
---------------------------------------------
--auto-close
	Dismiss the dialog when 100% has been reached
--auto-kill
	Kill parent process if Cancel button is pressed
--no-cancel
	Hide Cancel button
```

### Scale (slider) options

```
--text=TEXT
	Set the dialog text
--align=left|center|right
	Set text alignment
---------------------------------------------
--value=VALUE
	Set initial value
--min-value=VALUE
	Set minimum value
--max-value=VALUE
	Set maximum value
--step=VALUE
	Set step size
---------------------------------------------
--hide-value
	Hide value
--print-partial
	Print the value to the console each time it's changed by the user
```

### Text information options

```
--filename=Path to file
	Get content from the specified file
---------------------------------------------
--url=URL
	Get content from the specified URL (curl must be installed on the system)
--curl-path="Path to curl"
	Set path to the curl binary (default is "curl")
---------------------------------------------
--checkbox=TEXT
	Enable an I read and agree checkbox
---------------------------------------------
--editable
	Allow the user to edit text
--font=TEXT
	Set the text font
--plain
	Force plain text (zenity default limitation), otherwise guid will try
	to guess automatically the format
--html
	Force HTML format, otherwise guid will try to guess automatically the format
---------------------------------------------
--auto-scroll
	Auto scroll the text to the end (only when text is captured from stdin)
--no-interaction
	Do not enable user interaction with the WebView (only when "--html" is used)
```

### Warning options

```
--text=TEXT
	Set the dialog text
--ellipsize
	Do wrap text (zenity has a rather special problem here)
--no-markup
	Do not enable HTML markup
--no-wrap
	Do not enable text wrapping
---------------------------------------------
--icon-name=ICON_NAME
	Set the dialog icon
---------------------------------------------
--selectable-labels
	Allow to select text for copy and paste
```
