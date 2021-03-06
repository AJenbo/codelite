#include "clPythonLocator.hpp"
#include "file_logger.h"
#include "globals.h"
#include "wx/filename.h"
#ifdef __WXMSW__
#include "clRegistery.hpp"
#include "wx/msw/registry.h"
#endif

clPythonLocator::clPythonLocator() {}

clPythonLocator::~clPythonLocator() {}

bool clPythonLocator::Locate()
{
#ifdef __WXMSW__
    return MSWLocate();
#else
    wxFileName exepath;
    wxFileName pippath;
    if(::clFindExecutable("python", exepath)) { m_python = exepath.GetFullPath(); }
    if(::clFindExecutable("pip", pippath)) { m_pip = pippath.GetFullPath(); }
    return exepath.FileExists();
#endif
}

bool clPythonLocator::MSWLocate()
{
#ifdef __WXMSW__
    clRegistery reg("SOFTWARE\\Python\\PythonCore");
    wxString child = reg.GetFirstChild();
    if(child.IsEmpty()) { return false; }

    clRegistery regChild(child + "\\InstallPath");
    m_python = regChild.ReadValueString("ExecutablePath");
    if(!m_python.empty()) {
        clDEBUG() << "Python exe located at:" << m_python;

        wxFileName fnPip(m_python);
        fnPip.AppendDir("Scripts");
        fnPip.SetName("pip");
        m_pip = fnPip.GetFullPath();
        // Try to locate pip
        return true;
    } else {
        clDEBUG() << "No python installation found";
    }
    return false;
#endif
    return false;
}
