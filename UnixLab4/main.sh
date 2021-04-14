#!/bin/sh

file_name=$(zenity --file-selection --title="Choose file")

properties=$(stat $file_name)

result=$(zenity --info --title="File properties" --width=300 --height=150 \
	--text="File properties:\n $properties" --ok-label="Ok")
