// Author Kemi Peng.
// It's only a part of my codes, but it works
for ( UINT m = 0; m < sdkMeshLod.pMesh->GetNumMeshes(); m++ )
{
    ID3D10Buffer* pvb;       
    D3D10_BUFFER_DESC bufferdesc;        
    bufferdesc.BindFlags= 0;      
    bufferdesc.ByteWidth=sdkMeshLod.pMesh->GetVBSizeBytes( m, 0 );    
    bufferdesc.CPUAccessFlags=D3D10_CPU_ACCESS_READ;
    bufferdesc.MiscFlags=0;
    bufferdesc.Usage=D3D10_USAGE_STAGING;
    
    //try to get vertex buffer, http://msdn.microsoft.com/en-us/library/bb204896(VS.85).aspx
    pDevice->getD3DDevice()->CreateBuffer(&bufferdesc,NULL ,&pvb);
    //create a new buffer
    pDevice->getD3DDevice()->CopyResource(pvb,sdkMeshLod.pMesh->GetVB10(m,0))        
    void* data = NULL;
    pvb->Map(D3D10_MAP_READ ,NULL,&data);   //the counter part of LockVertexBuffer from d3d9.0
    
    //now, variable data is holding the vertex，you can use it to do a lot of things，like calculating aabb box, colliding detection
    
    pvb->Unmap();   //the counter part of UnlockVertexBuffer from d3d9.0
}