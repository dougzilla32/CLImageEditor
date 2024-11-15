import os
import shutil
import json

# Configuration
source_directory = '/Users/doug/Desktop/SwiftProjectsLaptop/CLImageEditor/Sources/CLImageEditor/CLImageEditor.bundle'  # Change this to your source directory
output_directory = '/Users/doug/Desktop/SwiftProjectsLaptop/CLImageEditor/Sources/CLImageEditor/AssetsTemp'  # Change this to your desired output directory
xcassets_bundle_name = 'Assets.xcassets'

# Function to flatten the directory and create xcassets
def flatten_and_create_xcassets(source_dir, output_dir):
    # Create the output xcassets directory
    xcassets_path = os.path.join(output_dir, xcassets_bundle_name)
    os.makedirs(xcassets_path, exist_ok=True)
    
    # Traverse the directory hierarchy
    for root, _, files in os.walk(source_dir):
        for file in files:
            print(f"File {file}")
            if file.endswith('.png'):
                # Create a flattened name by replacing '/' with '-'
                relative_path = os.path.relpath(root, source_dir)
                flattened_name = relative_path.replace(os.sep, '-') + '-' + file if relative_path != '.' else file
                
                # Ensure the name is valid for xcassets
                image_set_name = flattened_name.rsplit('.', 1)[0] + '.imageset'
                image_set_path = os.path.join(xcassets_path, image_set_name)
                os.makedirs(image_set_path, exist_ok=True)
                
                # Copy the PNG file to the new imageset directory
                source_file_path = os.path.join(root, file)
                destination_file_path = os.path.join(image_set_path, file)
                shutil.copy2(source_file_path, destination_file_path)
                
                # Create Contents.json for the imageset
                contents_json = {
                    "images": [
                        {
                            "filename": file,
                            "idiom": "universal",
                            "scale": "1x"
                        }
                    ],
                    "info": {
                        "version": 1,
                        "author": "xcode"
                    }
                }
                
                # Save the Contents.json file
                with open(os.path.join(image_set_path, 'Contents.json'), 'w') as json_file:
                    json.dump(contents_json, json_file, indent=4)

    print(f"Successfully created {xcassets_path}")

# Run the function
flatten_and_create_xcassets(source_directory, output_directory)
