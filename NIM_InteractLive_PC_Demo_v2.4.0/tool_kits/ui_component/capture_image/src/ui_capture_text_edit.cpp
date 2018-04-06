#include "ui_capture_text_edit.h"
#include "capture_def.h"

CCaptureTextEdit::CCaptureTextEdit(const ui::UiRect &rect)
{
	rc_valid_ = rect;
	white_brush_ = CreateSolidBrush(RGB(255, 255, 255));
}

CCaptureTextEdit::~CCaptureTextEdit()
{
	// �ͷž��
	DeleteObject(white_brush_);
}

void CCaptureTextEdit::HandleMessage( ui::EventArgs& event )
{
	// ���༭��ʧȥ�����ʱ��
	if(event.Type == ui::kEventKillFocus)
	{
		// ��ʱ��겻�����ı��༭����
		if(!::PtInRect(&rc_valid_, event.ptMouse))
		{
			//TODO::
			return;
		}
	}
	return ui::RichEdit::HandleMessage(event); 
}

void CCaptureTextEdit::Paint( HDC hDC, const ui::UiRect& rcPaint )
{
	DrawRect(hDC); // ���ƾ�������
	return __super::Paint(hDC, rcPaint);
}

void CCaptureTextEdit::DrawRect( HDC hdc )
{
	ui::UiRect rcEdit = rc_valid_; // Ҫ���Ƶ����� 
	InflateRect(&rcEdit, knEditOffset, knEditOffset); // ������չ3px
	HPEN dot_pen = CreatePen(PS_DOT, 1, color_pen_);
	HPEN old_pen = (HPEN)SelectObject(hdc, dot_pen);
	HBRUSH old_brush = (HBRUSH)SelectObject(hdc, white_brush_);
	// ���ư׵׵����߿�
	Rectangle(hdc, rcEdit.left, rcEdit.top, rcEdit.right, rcEdit.bottom);
	// ��ԭ
	SelectObject(hdc, old_pen);
	SelectObject(hdc, old_brush);
	// �ͷ�
	DeleteObject(dot_pen);
}

