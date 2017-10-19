try:  #Python 2
    from urllib import urlretrieve
except ImportError:   # Python 3
    from urllib.request import urlretrieve

import sys
import os
import zipfile

def local_install_pynwb():
    # Download PyNWB
    urlretrieve("https://github.com/NeurodataWithoutBorders/pynwb/archive/dev.zip", "pynwb-dev.zip")
    # Unzip the file
    with zipfile.ZipFile("pynwb-dev.zip","r") as zip_ref:
        zip_ref.extractall("../")
    # Remove the PyNWB docs in order not to confuse ReadTheDocs
    import shutil
    shutil.rmtree('../pynwb-dev/docs')
    # Add FORM and PyNWB to the path
    sys.path.append(os.path.abspath("../pynwb-dev/src"))


def pynwb_available():
    try:
        import pynwb
        return True
    except ImportError:
        return False

if not pynwb_available():
    local_install_pynwb()