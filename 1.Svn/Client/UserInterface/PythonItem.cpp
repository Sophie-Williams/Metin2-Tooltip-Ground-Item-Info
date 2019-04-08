//Find in : void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop)
	CItemData * pItemData;
	if (!CItemManager::Instance().GetItemDataPointer(dwVirtualNumber, &pItemData))
		return;
	
///Add
#ifdef TOOLTIP_GROUND_ITEM
	pItemData->SetSocAttr(sockets, attrtype, attrvals);
#endif

//Find
void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop)

///Change
#ifdef TOOLTIP_GROUND_ITEM
void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, std::vector<long> sockets, std::vector<BYTE> attrtype, std::vector<short> attrvals, float x, float y, float z, bool bDrop)
#else
void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop)
#endif