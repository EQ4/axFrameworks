#!/bin/bash

# Make script executable : chmod +x build.sh

# -laxEvent -laxUtils -laxGL -laxCore -laxWidget -laxAudio -laxAudioWidget -lpng -lfreetype -lportaudio -lsndfile

libs=( axEvent 
	   axUtils 
	   axGL
	   axExec
	   axCore
	   axWidget
       axDatabase);

function build 
{
	echo "BUILDING FUNCTION";

	cd modules/

	for d in ${libs[*]}; do
		echo $d;
		cd $d;
		make
		cp lib/lib$d.a ../../lib/
		cd ../;
	done
}

function build_combine_lib
{
	echo COMBINE LIB
	obj_list=();

	combine_libs=( axEvent 
				   axUtils 
	   	           axGL
	   	           axCore
	   	           axWidget
		           axExec
				   axDatabase );

	for d in ${combine_libs[*]}; do
		echo $d;
		obj_list+=(modules/$d/build/*.o);
	done

	# echo ${obj_list[*]}

	cd ../
	ar rsc lib/libaxLibCore.a ${obj_list[*]}
	
	#g++-4.9 -shared -o lib/libaxLibCore.so ${obj_list[*]}
	clang++ -shared -undefined dynamic_lookup -o lib/libaxLibCore.so ${obj_list[*]}
}

function build_single_module
{
	# echo "BUILDING MODULE " "$1";

	cd modules/
	cd "$1";
	make
	cp lib/lib"$1".a ../../lib/
	cd ../;
}

function clean 
{
	# echo "Cleaning FUNCTION";

	cd modules/

	for d in ${libs[*]}; do
		cd $d;
		make clean
		rm -f ../../lib/lib$d.a
		cd ../;
	done
}

function clean_single_module
{
	cd modules/
	cd "$1";
	make clean
	rm -f ../../lib/lib"$1".a
	cd ../;
}

function install 
{
	mkdir -p /usr/local/include/axLib/

	for d in ${libs[*]}; do
		cp -v modules/$d/include/*.{h,hpp} /usr/local/include/axLib/ 2> /dev/null
	done

	# Copy all .a lib.
	cp -v lib/*.a /usr/local/lib/ 2> /dev/null
	cp -v lib/*.so /usr/local/lib/ 2> /dev/null
}

opt="$1"
opt2="$2"

mkdir -p ./lib/ 

#------------------------------------------------------------------------------
# Option : build
#------------------------------------------------------------------------------
if [ "$opt" == "build" ]; then

	if [[ ${libs[*]} =~ (^| )"$opt2"($| ) ]]; then
		build_single_module "$opt2"

	elif [ "$opt2" == "" -o "$opt2" == "all" ]; then
		build;
		build_combine_lib;



	else
		echo "ERROR"
	fi

#------------------------------------------------------------------------------
# Option : clean
#------------------------------------------------------------------------------
elif [ "$opt" == "clean" ]; then

	if [[ ${libs[*]} =~ (^| )"$opt2"($| ) ]]; then
		clean_single_module "$opt2"

	elif [ "$opt2" == "" -o "$opt2" == "all" ]; then
		clean;

	else
		echo "ERROR"
	fi

#------------------------------------------------------------------------------
# Option : status
#------------------------------------------------------------------------------
elif [ "$opt" == "status" ]; then
	echo "STATUS"

#------------------------------------------------------------------------------
# Option : install
#------------------------------------------------------------------------------
elif [ "$opt" == "install" ]; then
	install;

#------------------------------------------------------------------------------
# Option : none
#------------------------------------------------------------------------------
else
	echo "Count is not 100"
fi
