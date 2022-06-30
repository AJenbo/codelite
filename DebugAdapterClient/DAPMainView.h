#ifndef DAPMAINVIEW_H
#define DAPMAINVIEW_H

#include "UI.h"
#include "clModuleLogger.hpp"
#include "dap/Client.hpp"
#include "dap/DAPEvent.hpp"
#include "dap/dap.hpp"

#include <unordered_set>

// variable items client data
struct VariableClientData : public wxTreeItemData {
    int reference = wxNOT_FOUND;
    wxString value; // untrucated value
    VariableClientData(int ref, const wxString& v)
        : reference(ref)
        , value(v)
    {
    }
    virtual ~VariableClientData() {}
};

enum class FrameOrThread {
    THREAD,
    FRAME,
};

// every entry in the threads tree has this item data
struct FrameClientData : public wxTreeItemData {
    int id = wxNOT_FOUND;
    FrameOrThread type;
    wxString value; // untrucated value
    FrameClientData(int frame_or_thread_id, FrameOrThread t)
        : id(frame_or_thread_id)
        , type(t)
    {
    }
    virtual ~FrameClientData() {}

    bool IsFrame() const { return type == FrameOrThread::FRAME; }
    bool IsThread() const { return type == FrameOrThread::THREAD; }
};

/// --------------------------------------------------------------------

class DAPMainView : public DAPMainViewBase
{
    dap::Client* m_client = nullptr;

    // the variables displayed in the view are owned by this frame Id
    int m_scopesFrameId = wxNOT_FOUND;

    clModuleLogger& LOG;

protected:
    wxTreeItemId FindThreadNode(int threadId);
    wxTreeItemId FindVariableNode(int refId);

    FrameClientData* GetFrameClientData(const wxTreeItemId& item);
    VariableClientData* GetVariableClientData(const wxTreeItemId& item);

    int GetThreadId(const wxTreeItemId& item);
    int GetVariableId(const wxTreeItemId& item);
    int GetFrameId(const wxTreeItemId& item);

    void OnThreadItemExpanding(wxTreeEvent& event);
    void OnFrameItemSelected(wxTreeEvent& event);
    void OnScopeItemExpanding(wxTreeEvent& event);
    void Clear();

public:
    DAPMainView(wxWindow* parent, dap::Client* client, clModuleLogger& log);
    virtual ~DAPMainView();

    void UpdateThreads(int activeThreadId, dap::ThreadsResponse* response);
    void UpdateFrames(int threadId, dap::StackTraceResponse* response);
    void UpdateScopes(int frameId, dap::ScopesResponse* response);
    void UpdateVariables(int parentRef, dap::VariablesResponse* response);
    /**
     * @brief return list of thread-id that are expanded in the UI
     */
    std::unordered_set<int> GetExpandedThreads();
};
#endif // DAPMAINVIEW_H
