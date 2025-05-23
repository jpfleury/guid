#pragma once

#include <QList>
#include <QMap>
#include <QObject>
#include <QString>

typedef QPair<QString, QString> Help;
typedef QList<Help> HelpList;
typedef QPair<QString, HelpList> CategoryHelp;
typedef QMap<QString, CategoryHelp> HelpDict;

inline HelpDict createHelpDict() {
HelpDict helpDict;

/******************************
 * help
 ******************************/

helpDict["help"] = CategoryHelp(QObject::tr("Help options"), HelpList() <<
Help("-h, --help",
     QObject::tr("Show help options")) <<
Help("--help-all",
     QObject::tr("Show all help options")) <<
Help("--help-general",
     QObject::tr("Show general options")) <<
Help("--help-misc",
     QObject::tr("Show miscellaneous options")) <<
Help("", "") <<

Help("--help-calendar",
     QObject::tr("Show calendar options")) <<
Help("--help-color-selection",
     QObject::tr("Show color selection options")) <<
Help("--help-entry",
     QObject::tr("Show text entry options")) <<
Help("--help-error",
     QObject::tr("Show error dialog options")) <<
Help("--help-file-selection",
     QObject::tr("Show file selection options")) <<
Help("--help-forms",
     QObject::tr("Show forms dialog options")) <<
Help("--help-info",
     QObject::tr("Show info dialog options")) <<
Help("--help-list",
     QObject::tr("Show list options")) <<
Help("--help-notification",
     QObject::tr("Show notification icon options")) <<
Help("--help-password",
     QObject::tr("Show password dialog options")) <<
Help("--help-progress",
     QObject::tr("Show progress options")) <<
Help("--help-question",
     QObject::tr("Show question options")) <<
Help("--help-scale",
     QObject::tr("Show scale options")) <<
Help("--help-text-info",
     QObject::tr("Show text information options")) <<
Help("--help-warning",
     QObject::tr("Show warning dialog options")));

/******************************
 * misc
 ******************************/

helpDict["misc"] = CategoryHelp(QObject::tr("Miscellaneous options"), HelpList() <<
Help("--about",
     QObject::tr("About guid")) <<
Help("--short-version",
     QObject::tr("Print plain version number only")) <<
Help("--version",
     QObject::tr("Print version with program name")));

/******************************
 * general
 ******************************/

helpDict["general"] = CategoryHelp(QObject::tr("General options"), HelpList() <<
Help("--title=TITLE",
     QObject::tr("Set the dialog title")) <<
Help("--window-icon=/path/to/icon",
     QObject::tr("Set the window icon")) <<
Help("--width=WIDTH",
     QObject::tr("Set the dialog width")) <<
Help("--height=HEIGHT",
     QObject::tr("Set the dialog height")) <<
Help("", "") <<

Help("--ok-label=TEXT",
     QObject::tr("Set the label of the Ok button")) <<
Help("--cancel-label=TEXT",
     QObject::tr("Set the label of the Cancel button")) <<
Help("", "") <<

Help("--timeout=TIMEOUT",
     QObject::tr("Set dialog timeout in seconds")) <<
Help("--always-on-top",
     QObject::tr("Force the dialog to be always on top of other windows")) <<
Help("--no-taskbar",
     QObject::tr("Don't display the dialog in the taskbar")) <<
Help("--attach=WINDOW",
     QObject::tr("Set the parent window to attach to")) <<
Help("--modal",
     QObject::tr("Set the modal hint")) <<
Help("--output-prefix-ok=PREFIX",
     QObject::tr("Set prefix for output sent to stdout")) <<
Help("--output-prefix-err=PREFIX",
     QObject::tr("Set prefix for output sent to stderr")));

/******************************
 * application
 ******************************/

helpDict["application"] = CategoryHelp(QObject::tr("Application options"), HelpList() <<
Help("--display=DISPLAY",
     QObject::tr("X display to use")) <<
Help("", "") <<

Help("--calendar",
     QObject::tr("Display calendar dialog")) <<
Help("--color-selection",
     QObject::tr("Display color selection dialog")) <<
Help("--entry",
     QObject::tr("Display text entry dialog")) <<
Help("--error",
     QObject::tr("Display error dialog")) <<
Help("--file-selection",
     QObject::tr("Display file selection dialog")) <<
Help("--font-selection",
     QObject::tr("Display font selection dialog")) <<
Help("--forms",
     QObject::tr("Display forms dialog")) <<
Help("--info",
     QObject::tr("Display info dialog")) <<
Help("--list",
     QObject::tr("Display list dialog")) <<
Help("--notification",
     QObject::tr("Display notification")) <<
Help("--password",
     QObject::tr("Display password dialog")) <<
Help("--progress",
     QObject::tr("Display progress indication dialog")) <<
Help("--question",
     QObject::tr("Display question dialog")) <<
Help("--scale",
     QObject::tr("Display scale dialog")) <<
Help("--text-info",
     QObject::tr("Display text information dialog")) <<
Help("--warning",
     QObject::tr("Display warning dialog")));

/******************************
 * calendar
 ******************************/

helpDict["calendar"] = CategoryHelp(QObject::tr("Calendar options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("--align=left|center|right",
     QObject::tr("Set text alignment")) <<
Help("", "") <<

Help("--day=DAY",
     QObject::tr("Set the calendar day")) <<
Help("--month=MONTH",
     QObject::tr("Set the calendar month")) <<
Help("--year=YEAR",
     QObject::tr("Set the calendar year")) <<
Help("--date-format=PATTERN",
     QObject::tr("Set the format for the returned date")) <<
Help("", "") <<

Help("--timeout=TIMEOUT",
     QObject::tr("Set dialog timeout in seconds")));

/******************************
 * color-selection
 ******************************/

helpDict["color-selection"] = CategoryHelp(QObject::tr("Color selection options"), HelpList() <<
Help("--color=VALUE",
     QObject::tr("Set the color")) <<
Help("--custom-palette=/path/to/file.gpl",
     QObject::tr("Load a custom GPL file for standard colors")) <<
Help("--show-palette",
     QObject::tr("Show the palette")));

/******************************
 * entry
 ******************************/

helpDict["entry"] = CategoryHelp(QObject::tr("Text entry options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("", "") <<

Help("--entry-text=TEXT",
     QObject::tr("Set the entry text")) <<
Help("--hide-text",
     QObject::tr("Hide the entry text")) <<
Help("", "") <<

Help("--float=FLOATING_POINT",
     QObject::tr("Floating point input only, preset given value")) <<
Help("--int=INTEGER",
     QObject::tr("Integer input only, preset given value")) <<
Help("--values=v1|v2|v3|...",
     QObject::tr("Offer preset values to pick from")));

/******************************
 * error
 ******************************/

helpDict["error"] = CategoryHelp(QObject::tr("Error options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("--ellipsize",
     QObject::tr("Do wrap text (zenity has a rather special problem here)")) <<
Help("--no-markup",
     QObject::tr("Do not enable HTML markup")) <<
Help("--no-wrap",
     QObject::tr("Do not enable text wrapping")) <<
Help("", "") <<

Help("--icon-name=ICON_NAME",
     QObject::tr("Set the dialog icon")) <<
Help("", "") <<

Help("--selectable-labels",
     QObject::tr("Allow to select text for copy and paste")));

/******************************
 * file-selection
 ******************************/

helpDict["file-selection"] = CategoryHelp(QObject::tr("File selection options"), HelpList() <<
Help("--filename=/path/to/file",
     QObject::tr("Set the file selected by default")) <<
Help("--file-filter=NAME|PATTERN1 PATTERN2...",
     QObject::tr("Set a filename filter")) <<
Help("--directory",
     QObject::tr("Activate directory-only selection")) <<
Help("--multiple",
     QObject::tr("Allow multiple files to be selected")) <<
Help("", "") <<

Help("--confirm-overwrite",
     QObject::tr("Confirm file selection if the file selected already exists")) <<
Help("--save",
     QObject::tr("Activate save mode")) <<
Help("", "") <<

Help("--separator=SEPARATOR",
     QObject::tr("Set output separator character")));

/******************************
 * font-selection
 ******************************/

helpDict["font-selection"] = CategoryHelp(QObject::tr("Font selection options"), HelpList() <<
Help("--sample=TEXT",
     QObject::tr("Sample text (default is \"The quick brown fox jumps over the lazy dog.\"")) <<
Help("--pattern=%1-%2:%3:%4",
     QObject::tr("Output pattern where %1 is name, %2 is size, %3 is weight, %4 is slant.")) <<
Help("--type=[vector][,bitmap][,fixed][,variable]",
     QObject::tr("Filter fonts (default is all)")));

/******************************
 * forms
 ******************************/

const char *formsVarHelp = R"HEREDOC(Variable name added before the field value when printed to the console.
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
cal=2020-12-12|pseudo=Little Mouse)HEREDOC";

helpDict["forms"] = CategoryHelp(QObject::tr("Forms dialog options"), HelpList() <<

// Widget settings
Help(QObject::tr(R"HEREDOC(Widgets are added to forms dialog using the following syntax:
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
The list of variables supported is displayed at the beginning of each widget section.)HEREDOC"), "") <<
Help("", "") <<

// --text
Help("--text=\"Form label (form description)\"",
     QObject::tr("Set the form label (always displayed on top, and bold by default")) <<
Help("--align=left|center|right",
     QObject::tr("Set label alignment")) <<
Help("--no-bold",
     QObject::tr("Remove bold for the form label")) <<
Help("--italics",
     QObject::tr("Set form label in italics")) <<
Help("--underline",
     QObject::tr("Set form label format to underline")) <<
Help("--small-caps",
     QObject::tr("Set form label rendering to small-caps type")) <<
Help("--font-family=FAMILY",
     QObject::tr("Set font family for the form label")) <<
Help("--font-size=SIZE",
     QObject::tr("Set font size for the form label")) <<
Help("--foreground-color=COLOR",
     QObject::tr(R"HEREDOC(Set form label color. Example:
guid --forms \
 --text="Form label (form description)" \
     --foreground-color="#0000FF" \
 --add-entry="Entry field not colored")HEREDOC")) <<
Help("--background-color=COLOR",
     QObject::tr(R"HEREDOC("Set form label background color. Example:
guid --forms \
 --text="Form label (form description)" \
 --background-color="#0000FF" \
 --add-entry="Entry field not colored")HEREDOC")) <<
Help("", "") <<

// --header
Help(R"HEREDOC(--header="[backgroundColor=COLOR@][foregroundColor=COLOR@][hideLabel=true@]
  [stop=true@]Header label")HEREDOC",
     QObject::tr(R"HEREDOC("Add a header to the form.
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
 --add-entry="Field outside the header")HEREDOC")) <<
Help("", "") <<

// --group
Help("--group=\"[addLabel=Group label@][stop=true@]Group name\"",
     QObject::tr(R"HEREDOC(Add a group box (fieldset).
Next fields will be added to the group unless a new "--group" is added containing
the variable "stop=true". Example:
guid --forms \
 --text="Form with a group box (fieldset)" \
 --group="Group name" \
     --add-entry="Text field in the group" \
     --add-entry="Another text field in the group" \
 --group="stop=true" \
 --add-text="Text outside the group")HEREDOC")) <<
Help("", "") <<

// --tab
Help(R"HEREDOC(--tab="[addLabel=Tab bar label@][disableButtons=true@][selected=true@]
   [stop=true@][verboseTabBar=true@]Tab name")HEREDOC",
     QObject::tr(R"HEREDOC(Create a tab bar.
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
fields and the selected tab will be marked with "*".)HEREDOC")) <<
Help("", "") <<

// --col1 || --col2
Help("--col1",
     QObject::tr(R"HEREDOC(Start a two-field row.
The next form field specified will be added in the first column. See "--col2" for
details.)HEREDOC")) <<
Help("--col2",
     QObject::tr(R"HEREDOC(Finish a two-field row.
The next form field specified will be added in the second column. Example:
guid --forms --width=500 \
 --text="The next row has two columns:" \
 --col1 \
     --add-entry="Left entry (column 1)" --int=5 \
 --col2 \
     --add-entry="Right entry (column 2)" --field-width=100 \
 --add-entry="Outside columns")HEREDOC")) <<
Help("--add-hspacer=before|after",
     QObject::tr(R"HEREDOC(Add horizontal expanding spacer before or after the current
column content)HEREDOC")) <<
Help("--valign=top|center|bottom|baseline",
     QObject::tr(R"HEREDOC(Set vertical alignment of the current column. Example:
guid --forms --width=500 \
 --text="The next row has two columns:" \
 --col1 --valign=bottom \
     --add-text="Aligned to the bottom" \
 --col2 \
     --add-text="Lorem<br />ipsum<br />dolor<br />sit<br />amet" \
 --add-entry="Outside columns")HEREDOC")) <<
Help("", "") <<

// --add-calendar
Help("--add-calendar=\"[hideLabel=true@]Calendar label\"",
     QObject::tr("Add a calendar in forms dialog")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-checkbox
Help("--add-checkbox=\"[addLabel=Checkbox label@]Checkbox text\"",
     QObject::tr("Add a checkbox in forms dialog")) <<
Help("--checked",
     QObject::tr("Make the checkbox checked by default")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-combo
Help("--add-combo=\"[hideLabel=true@]Combo label\"",
     QObject::tr("Add a combo box in forms dialog")) <<
Help("--combo-values=[defaultIndex=Index number@]List of values separated by |",
     QObject::tr(R"HEREDOC(List of values for the combo box.
To select a specific index by default, add the variable "defaultIndex=Index number".)HEREDOC")) <<
Help("--combo-values-from-file=[defaultIndex=Index number@][monitor=VALUE@]Path to file",
     QObject::tr(R"HEREDOC(Use the file content as combo values (one value per line).
To select a specific index by default, add the variable "defaultIndex=Index number".
To monitor file changes, add "monitor=true". Example:
guid --forms \
 --add-combo="Combo label" \
 --combo-values-from-file="defaultIndex=1@monitor=true@C:\\Path\\to\\file.txt")HEREDOC")) <<
Help("--editable",
     QObject::tr("Allow the user to edit combo values")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-entry
Help("--add-entry=\"[hideLabel=true@]Entry label\"",
     QObject::tr("Add a text entry in forms dialog")) <<
Help("--float=FLOATING_POINT",
     QObject::tr("Floating point input only, preset given value")) <<
Help("--int=INTEGER",
     QObject::tr("Integer input only, preset given value")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-file-selection
Help("--add-file-selection=\"[buttonText=Text@][hideLabel=true@]File selection label\"",
     QObject::tr(R"HEREDOC(File selection options.
The field name is displayed in a button that opens the file selection dialog.
The selection is added and displayed in a text entry.)HEREDOC")) <<
Help("--filename=/path/to/file",
     QObject::tr("Set the file selected by default")) <<
Help("--file-filter=NAME|PATTERN1 PATTERN2...",
     QObject::tr("Set a filename filter")) <<
Help("--directory",
     QObject::tr("Activate directory-only selection")) <<
Help("--multiple",
     QObject::tr("Allow multiple files to be selected")) <<
Help("--file-separator=SEPARATOR",
     QObject::tr(R"HEREDOC(Set output separator character if there are multiple files selected
(default is "~"))HEREDOC")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("", "") <<

// --add-list
Help(R"HEREDOC(--add-list="[addNewRowButton=true@][excludeFromOutput=true@]
    [hideLabel=true@]List label")HEREDOC",
     QObject::tr(R"HEREDOC(Add a list in forms dialog.
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
     --list-values="v1|v2|v3|v4" --editable)HEREDOC")) <<
Help("--column-values=Column names separated by |",
     QObject::tr("List of column names")) <<
Help("--list-values=List values separated by |",
     QObject::tr("List values")) <<
Help("--list-values-from-file=\"[addValue=Value@][monitor=true@][sep=Separator@]Path to file\"",
     QObject::tr(R"HEREDOC(Use the file content as list values. Example:
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
     --list-values-from-file="monitor=true@sep=,@/path/to/file")HEREDOC")) <<
Help("--checklist",
     QObject::tr("Add checkboxes in the first column (multiple rows will be selectable)")) <<
Help("--radiolist",
     QObject::tr("Add radio buttons in the first column (only one row will be selectable)")) <<
Help("--editable",
     QObject::tr("Allow the user to edit list values")) <<
Help("--read-only-column=Column number",
     QObject::tr("If editable, set a specific column as read only")) <<
Help("--multiple",
     QObject::tr("Allow multiple rows to be selected")) <<
Help("--no-selection",
     QObject::tr(R"HEREDOC(Prevent row selection (useful to display information in a structured way
without user interaction))HEREDOC")) <<
Help("--print-column=NUMBER|all",
     QObject::tr(R"HEREDOC(Print a specific column to the console.
Default is "1" (print only the first column). The value "all" can be used to print
all columns.)HEREDOC")) <<
Help("--print-values=selected|all",
     QObject::tr(R"HEREDOC(Print selected values (by default) or all values (useful in combination
with "--editable" to get updated values).)HEREDOC")) <<
Help("--list-row-separator=SEPARATOR",
     QObject::tr("Set output separator character for list rows (default is \"~\")")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--field-height=HEIGHT",
     QObject::tr("Set the field height")) <<
Help("--show-header",
     QObject::tr("Show the columns header")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-menu
Help("--add-menu=\"addLabel=Menu label@Menu settings\"",
     QObject::tr(R"HEREDOC(Add a menu in forms dialog.
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
 --add-text="Form label" --bold)HEREDOC")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets.)HEREDOC")) <<
Help("", "") <<

// --add-password
Help("--add-password=\"[hideLabel=true@]Password label\"",
     QObject::tr("Add a password entry in forms dialog")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-qr-code
Help("--add-qr-code=\"[addLabel=QR code label@][size=Size@]QR Code text\"",
     QObject::tr(R"HEREDOC(Add a QR code in forms dialog.
Note that this widget is not a user input field, so it doesn't appear in the console
(no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--align=left|center|right",
     QObject::tr("Set QR code alignment")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets.)HEREDOC")) <<
Help("", "") <<

// --add-scale
Help("--add-scale=\"[hideLabel=true@]Scale label\"",
     QObject::tr("Add a scale (slider) in forms dialog")) <<
Help("--value=VALUE",
     QObject::tr("Set initial value")) <<
Help("--min-value=VALUE",
     QObject::tr("Set minimum value")) <<
Help("--max-value=VALUE",
     QObject::tr("Set maximum value")) <<
Help("--step=VALUE",
     QObject::tr("Set step size")) <<
Help("--hide-value",
     QObject::tr("Hide value")) <<
Help("--print-partial",
     QObject::tr("Print the value to the console each time it's changed by the user")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-spin-box
Help("--add-spin-box=\"[hideLabel=true@]Spin box label\"",
     QObject::tr("Add a spin box in forms dialog")) <<
Help("--value=VALUE",
     QObject::tr("Set initial value")) <<
Help("--min-value=VALUE",
     QObject::tr("Set minimum value")) <<
Help("--max-value=VALUE",
     QObject::tr("Set maximum value")) <<
Help("--prefix=PREFIX",
     QObject::tr("Set prefix")) <<
Help("--suffix=SUFFIX",
     QObject::tr("Set suffix")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-double-spin-box
Help("--add-double-spin-box=\"[hideLabel=true@]Double spin box label\"",
     QObject::tr("Add a double spin box in forms dialog")) <<
Help("--value=VALUE",
     QObject::tr("Set initial value")) <<
Help("--decimals=VALUE",
     QObject::tr("Set the number of decimals")) <<
Help("--min-value=VALUE",
     QObject::tr("Set minimum value")) <<
Help("--max-value=VALUE",
     QObject::tr("Set maximum value")) <<
Help("--prefix=PREFIX",
     QObject::tr("Set prefix")) <<
Help("--suffix=SUFFIX",
     QObject::tr("Set suffix")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets. Note that a hidden widget is not a user input field,
so it doesn't appear in the console (no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-text
Help(R"HEREDOC(--add-text="[addLabel=Text label@][defMarkerVal1=Value@][image=Path to image@]
    [monitorMarkerFile1=Path to file@][monitorVarName1=Variable name@]Text")HEREDOC",
     QObject::tr(R"HEREDOC(Add text without field.
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
 --add-text="monitorMarkerFile1=/to/settings.sh@monitorVarName1=age@Age is GUID_MARKER_1.")HEREDOC")) <<
Help("--tooltip=Tooltip text",
     QObject::tr("Set tooltip displayed when the cursor is over")) <<
Help("--wrap",
     QObject::tr("Enable text wrapping")) <<
Help("--align=left|center|right",
     QObject::tr("Set text alignment")) <<
Help("--bold",
     QObject::tr("Set text in bold")) <<
Help("--italics",
     QObject::tr("Set text in italics")) <<
Help("--underline",
     QObject::tr("Set text format to underline")) <<
Help("--small-caps",
     QObject::tr("Set text rendering to small-caps type")) <<
Help("--font-family=FAMILY",
     QObject::tr("Set font family")) <<
Help("--font-size=SIZE",
     QObject::tr("Set font size")) <<
Help("--foreground-color=COLOR",
     QObject::tr(R"HEREDOC(Set text color. Example:
guid --forms \
 --add-text="Lorem ipsum" --foreground-color="#0000FF")HEREDOC")) <<
Help("--background-color=COLOR",
     QObject::tr(R"HEREDOC(Set text background color. Example:
guid --forms \
 --add-text="Lorem ipsum" --background-color="#0000FF")HEREDOC")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--field-height=HEIGHT",
     QObject::tr("Set the field height")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets.)HEREDOC")) <<
Help("", "") <<

// --add-hrule
Help("--add-hrule=\"[addLabel=Rule label@]Rule color",
     QObject::tr(R"HEREDOC(Add a horizontal rule with the color specified. Example:
guid --forms \
 --add-text="Lorem ipsum" \
 --add-hrule="#B1B1B1" \
 --add-entry="Text field"
Note that this widget is not a user input field, so it doesn't appear in the console
(no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--field-height=HEIGHT",
     QObject::tr("Set the field height")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets.)HEREDOC")) <<
Help("", "") <<

// --add-vspacer
Help("--add-vspacer=\"[addLabel=Vertical spacer label@]Height\"",
     QObject::tr(R"HEREDOC(Add a vertical spacer.
Note that this widget is not a user input field, so it doesn't appear in the console
(no even as empty value) when user input is printed.)HEREDOC")) <<
Help("", "") <<

// --add-text-info
Help("--add-text-info=\"[hideLabel=true@]Text info label\"",
     QObject::tr(R"HEREDOC(Add text information.
Note that this widget is a user input field only when the argument "--editable"
is used. Otherwise, it's not a user input field, so it doesn't appear in the console
(no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--filename=\"[monitor=true@]Path to file\"",
     QObject::tr("Get content from the specified file")) <<
Help("--url=URL", QObject::tr("Get content from the specified URL (curl must be installed on the system)")) <<
Help("--curl-path=\"Path to curl\"",
     QObject::tr("Set path to the curl binary (default is \"curl\")")) <<
Help("--editable",
     QObject::tr("Allow the user to edit text")) <<
Help("--plain",
     QObject::tr(R"HEREDOC(Force plain text (zenity default limitation), otherwise guid will try
to guess automatically the format)HEREDOC")) <<
Help("--html",
     QObject::tr("Force HTML format, otherwise guid will try to guess automatically the format")) <<
Help("--newline-separator=SEPARATOR",
     QObject::tr(R"HEREDOC(Replace newlines with SEPARATOR in the text printed to the console (so the
output is only on one line))HEREDOC")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--field-height=HEIGHT",
     QObject::tr("Set the field height")) <<
Help("--align=left|center|right",
     QObject::tr("Set text alignment")) <<
Help("--bold",
     QObject::tr("Set text in bold")) <<
Help("--italics",
     QObject::tr("Set text in italics")) <<
Help("--underline",
     QObject::tr("Set text format to underline")) <<
Help("--small-caps",
     QObject::tr("Set text rendering to small-caps type")) <<
Help("--font-family=FAMILY",
     QObject::tr("Set font family")) <<
Help("--font=TEXT",
     QObject::tr("Set the text font")) <<
Help("--font-size=SIZE",
     QObject::tr("Set font size")) <<
Help("--foreground-color=COLOR",
     QObject::tr(R"HEREDOC(Set text color. Example:
guid --forms \
 --add-text-info="Text info label" --foreground-color="#0000FF" \
     --filename="/path/to/file.txt")HEREDOC")) <<
Help("--background-color=COLOR",
     QObject::tr(R"HEREDOC(Set text background color. Example:
guid --forms \
 --add-text-info="Text info label" --background-color="#0000FF" \
     --filaneme="/path/to/file.txt")HEREDOC")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets.)HEREDOC")) <<
Help("--var=NAME",
     QObject::tr("Only when the field is editable.") + "\n" + QObject::tr(formsVarHelp)) <<
Help("", "") <<

// --add-text-browser
Help("--add-text-browser=\"[hideLabel=true@]Text browser label\"",
     QObject::tr(R"HEREDOC(Add read-only HTML information with click on links enabled.
Note that this widget is not a user input field, so it doesn't appear in the console
(no even as empty value) when user input is printed.)HEREDOC")) <<
Help("--filename=/path/to/file",
     QObject::tr("Get content from the specified file")) <<
Help("--url=URL", QObject::tr("Get content from the specified URL (curl must be installed on the system)")) <<
Help("--curl-path=\"Path to curl\"",
     QObject::tr("Set path to the curl binary (default is \"curl\")")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")) <<
Help("--field-height=HEIGHT",
     QObject::tr("Set the field height")) <<
Help("--hide",
     QObject::tr(R"HEREDOC(Hide the widget but retain its size in the dialog.
Useful mainly for positioning other widgets.)HEREDOC")) <<
Help("", "") <<

// Window buttons
Help("--win-min-button",
     QObject::tr("Add a \"Minimize\" button to the dialog window")) <<
Help("--win-max-button",
     QObject::tr("Add a \"Maximize\" button to the dialog window")) <<
Help("", "") <<

// System tray
Help("--close-to-systray",
     QObject::tr(R"HEREDOC(Hide the dialog (instead of exiting) when clicking the window "Close" button.
The system tray must be enabled with --systray-icon="Path to icon".)HEREDOC")) <<
Help("--systray-icon=\"Path to icon\"",
     QObject::tr(R"HEREDOC(Add the icon specified in the system tray.
Clicking the "Close" window button will minimize the dialog in the systray, and a
menu will be displayed with a right-click on the systray icon.)HEREDOC")) <<
Help("", "") <<

// Dialog buttons
Help(R"HEREDOC(--action-after-ok-click="[keepOpen=true@]
                 [valuesToFooter=true@][commandToFooter=true@]
                 [command=command name[<>command argument][<>another arg]")HEREDOC",
     QObject::tr(R"HEREDOC(Action after a click on the OK button.
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
"GUID_VALUES_BASE64_URL".)HEREDOC")) <<
Help("--no-cancel",
     QObject::tr("Hide Cancel button")) <<
Help("", "") <<

// Footer
Help("--footer-name=\"Footer name\"",
     QObject::tr("Name of the footer fieldset")) <<
Help("--footer-entries=\"Number of entries\"",
     QObject::tr(R"HEREDOC(Number of entries to display in the footer (most recent entries are always displayed first).
Default is 3.)HEREDOC")) <<
Help("--footer-from-file=\"[monitor=true@]Path to file\"",
     QObject::tr(R"HEREDOC(Use the file content as a source of footer entries.
To monitor file changes, add the variable "monitor=true".)HEREDOC")) <<
Help("", "") <<

// Misc.
Help("--forms-date-format=PATTERN",
     QObject::tr("Set the format for the returned date")) <<
Help("--forms-align=left|center|right",
     QObject::tr("Set label alignment for the entire form")) <<
Help("--separator=SEPARATOR",
     QObject::tr("Set output separator character")) <<
Help("--comment=COMMENT",
     QObject::tr(R"HEREDOC(Add comment for convenience in the command line arguments.
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
 --add-scale="Field outside the tab bar" --step=5)HEREDOC")));

/******************************
 * info
 ******************************/

helpDict["info"] = CategoryHelp(QObject::tr("Info options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("--ellipsize",
     QObject::tr("Do wrap text (zenity has a rather special problem here)")) <<
Help("--no-markup",
     QObject::tr("Do not enable HTML markup")) <<
Help("--no-wrap",
     QObject::tr("Do not enable text wrapping")) <<
Help("", "") <<

Help("--icon-name=ICON_NAME",
     QObject::tr("Set the dialog icon")) <<
Help("", "") <<

Help("--selectable-labels",
     QObject::tr("Allow to select text for copy and paste")));

/******************************
 * list
 ******************************/

helpDict["list"] = CategoryHelp(QObject::tr("List options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("--align=left|center|right",
     QObject::tr("Set text alignment")) <<
Help("", "") <<

Help("--checklist",
     QObject::tr("Add checkboxes in the first column (multiple rows will be selectable)")) <<
Help("--imagelist",
     QObject::tr("Use an image in the first column")) <<
Help("--radiolist",
     QObject::tr("Add radio buttons in the first column (only one row will be selectable)")) <<
Help("", "") <<

Help("--column=\"Column name\"",
     QObject::tr("Add a column")) <<
Help("--hide-column=NUMBER",
     QObject::tr("Hide a specific column")) <<
Help("--print-column=NUMBER|all",
     QObject::tr(R"HEREDOC(Print a specific column to the console.
Default is "1" (print only the first column). The value "all" can be used to print
all columns.)HEREDOC")) <<
Help("--hide-header",
     QObject::tr("Hide the column headers")) <<
Help("", "") <<

Help("--list-values-from-file=\"[monitor=true@][sep=Separator@]Path to file\"",
     QObject::tr(R"HEREDOC(Use the file content as list values.
To monitor file changes, add the variable "monitor=true". By default, the character
"|" is used as separator between values. To use another separator, specify it with
the variable "sep=Separator". Example:
guid --list \
 --text="List label" \
 --column="Column 1" --column="Column 2" \
 --list-values-from-file="monitor=true@sep=,@/path/to/file")HEREDOC")) <<
Help("", "") <<

Help("--editable",
     QObject::tr("Allow the user to edit list values")) <<
Help("--multiple",
     QObject::tr("Allow multiple rows to be selected")) <<
Help("--no-selection",
     QObject::tr(R"HEREDOC(Prevent row selection (useful to display information in a structured way
without user interaction))HEREDOC")) <<
Help("--print-values=selected|all",
     QObject::tr(R"HEREDOC(Print selected values (by default) or all values (useful in combination
with "--editable" to get updated values).)HEREDOC")) <<
Help("", "") <<

Help("--mid-search",
     QObject::tr(R"HEREDOC(Change list default search function searching for text in the middle, not at the
beginning)HEREDOC")) <<
Help("--field-height=HEIGHT",
     QObject::tr("Set the field height")) <<
Help("--separator=SEPARATOR",
     QObject::tr("Set output separator character")));

/******************************
 * notification
 ******************************/

helpDict["notification"] = CategoryHelp(QObject::tr("Notification icon options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("", "") <<

Help("--hint=TEXT",
     QObject::tr("Set the notification hints")) <<
Help("", "") <<

Help("--listen",
     QObject::tr("Listen for commands on stdin")) <<
Help("--selectable-labels",
     QObject::tr("Allow to select text for copy and paste")));

/******************************
 * password
 ******************************/

helpDict["password"] = CategoryHelp(QObject::tr("Password dialog options"), HelpList() <<
Help("--prompt=TEXT",
     QObject::tr("The prompt for the user (field label)")) <<
Help("--username",
     QObject::tr("Add a username field")) <<
Help("--field-width=WIDTH",
     QObject::tr("Set the field width")));

/******************************
 * progress
 ******************************/

helpDict["progress"] = CategoryHelp(QObject::tr("Progress options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("", "") <<

Help("--percentage=PERCENTAGE",
     QObject::tr("Set initial percentage")) <<
Help("--pulsate",
     QObject::tr("Pulsate progress bar")) <<
Help("", "") <<

Help("--auto-close",
     QObject::tr(R"HEREDOC(Dismiss the dialog when 100% has been reached)HEREDOC")) <<
Help("--auto-kill",
     QObject::tr("Kill parent process if Cancel button is pressed")) <<
Help("--no-cancel",
     QObject::tr("Hide Cancel button")));

/******************************
 * question
 ******************************/

helpDict["question"] = CategoryHelp(QObject::tr("Question options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("--ellipsize",
     QObject::tr("Do wrap text (zenity has a rather special problem here)")) <<
Help("--no-markup",
     QObject::tr("Do not enable HTML markup")) <<
Help("--no-wrap",
     QObject::tr("Do not enable text wrapping")) <<
Help("", "") <<

Help("--default-cancel",
     QObject::tr("Give Cancel button focus by default")) <<
Help("", "") <<

Help("--icon-name=ICON_NAME",
     QObject::tr("Set the dialog icon")) <<
Help("", "") <<

Help("--selectable-labels",
     QObject::tr("Allow to select text for copy and paste")));

/******************************
 * scale
 ******************************/

helpDict["scale"] = CategoryHelp(QObject::tr("Scale (slider) options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("--align=left|center|right",
     QObject::tr("Set text alignment")) <<
Help("", "") <<

Help("--value=VALUE",
     QObject::tr("Set initial value")) <<
Help("--min-value=VALUE",
     QObject::tr("Set minimum value")) <<
Help("--max-value=VALUE",
     QObject::tr("Set maximum value")) <<
Help("--step=VALUE",
     QObject::tr("Set step size")) <<
Help("", "") <<

Help("--hide-value",
     QObject::tr("Hide value")) <<
Help("--print-partial",
     QObject::tr("Print the value to the console each time it's changed by the user")));

/******************************
 * text-info
 ******************************/

helpDict["text-info"] = CategoryHelp(QObject::tr("Text information options"), HelpList() <<
Help("--filename=Path to file",
     QObject::tr("Get content from the specified file")) <<
Help("", "") <<

Help("--url=URL", QObject::tr("Get content from the specified URL (curl must be installed on the system)")) <<
Help("--curl-path=\"Path to curl\"",
     QObject::tr("Set path to the curl binary (default is \"curl\")")) <<
Help("", "") <<

Help("--checkbox=TEXT",
     QObject::tr("Enable an I read and agree checkbox")) <<
Help("", "") <<

Help("--editable",
     QObject::tr("Allow the user to edit text")) <<
Help("--font=TEXT",
     QObject::tr("Set the text font")) <<
Help("--plain",
     QObject::tr(R"HEREDOC(Force plain text (zenity default limitation), otherwise guid will try
to guess automatically the format)HEREDOC")) <<
Help("--html",
     QObject::tr("Force HTML format, otherwise guid will try to guess automatically the format")) <<
Help("", "") <<

Help("--auto-scroll",
     QObject::tr("Auto scroll the text to the end (only when text is captured from stdin)")) <<
Help("--no-interaction",
     QObject::tr("Do not enable user interaction with the WebView (only when \"--html\" is used)")));

/******************************
 * warning
 ******************************/

helpDict["warning"] = CategoryHelp(QObject::tr("Warning options"), HelpList() <<
Help("--text=TEXT",
     QObject::tr("Set the dialog text")) <<
Help("--ellipsize",
     QObject::tr("Do wrap text (zenity has a rather special problem here)")) <<
Help("--no-markup",
     QObject::tr("Do not enable HTML markup")) <<
Help("--no-wrap",
     QObject::tr("Do not enable text wrapping")) <<
Help("", "") <<

Help("--icon-name=ICON_NAME",
     QObject::tr("Set the dialog icon")) <<
Help("", "") <<

Help("--selectable-labels",
     QObject::tr("Allow to select text for copy and paste")));

return helpDict;
}

// vim:set noet sw=4 ts=4